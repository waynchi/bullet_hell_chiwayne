#include "MainWindow.h"

MainWindow::MainWindow()  {
  //We need a scene and a view to do graphics in QT
  left = false;
  right = false;
  up = false;
  down = false;
  space = false;
  pbulletcount = 0;
  bound = new QRectF(-300,-300,600,600);
  scene = new QGraphicsScene();
  view = new QGraphicsView( scene );
  view->setFixedSize(600, 600);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setSceneRect(*bound); 
  mainLayout = new QVBoxLayout;
  mainLayout->addWidget(view);
  setLayout(mainLayout);
  setFocus();
  
  PowerupObject = NULL;
  playerpixmap = new QPixmap("images/Player.png");
  PlayerBulletPixMap = new QPixmap("images/PlayerBulletActual.png");
  EnemyPixMap = new QPixmap("images/Enemy.png");
  EnemyBulletPixMap = new QPixmap("images/EnemyBulletActual.png");
  PowerupPixMap = new QPixmap("images/Powerup.png");
  AlliesPixMap = new QPixmap("images/AlliesActual.png");
  AlliesBulletPixMap = new QPixmap("images/AlliedBullet.png");
  playerobject = new Player(playerpixmap, 0,0);
  scene->addItem(playerobject);
  
  //Enemy
  int enemyspawn = (rand() % 570) - 300;
  Enemy *tempE = new Enemy(EnemyPixMap, enemyspawn, -360);
  tempE->setvY(rand()%6 + 2);
  tempE->setFiringRate(rand()%20 +40);
  EnemyList.push_back(tempE);
  scene->addItem(tempE);
  
  //Powerup
  PowerupObject = new Powerup(PowerupPixMap, 50,50);
  scene->addItem(PowerupObject);
  
  //Ally
  Ally *tempA = new Ally(AlliesPixMap, playerobject->getX() - 25 , playerobject->getY());
  AlliesList.push_back(tempA);
  scene->addItem(tempA);
 
  
  
  timer = new QTimer(this);
  timer->setInterval(50);
  timer->start();
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
}

MainWindow::~MainWindow() {

}

void MainWindow::handleTimer()
{
  setFocus();
  playerobject->change(left, right, up, down);
  playerobject->move();
  if(PowerupObject != NULL)
  {
    PowerupObject->move();
  }
  for (unsigned int i = 0; i < PlayerBulletList.size(); i++)
  {
  	PlayerBulletList[i]->move();
  }
  for (unsigned int j = 0; j < EnemyList.size(); j++)
  {
  	EnemyList[j]->move();
  	if(EnemyList[j]->count > 0)
  	{
  	  EnemyList[j]->count--;
  	}
  	if(EnemyList[j]->count == 0)
  	{
  	  EnemyBullet *tempEB = new EnemyBullet(EnemyBulletPixMap, EnemyList[j]->getX()+15, EnemyList[j]->getY()+60);
  	  EnemyBulletList.push_back(tempEB);
    	  scene->addItem(tempEB);
    	  EnemyList[j]->count = EnemyList[j]->getFiringRate();
    	}
  }
  for (unsigned int k = 0; k < EnemyBulletList.size(); k++)
  {
  	EnemyBulletList[k]->move();
  }
  for (unsigned int b = 0; b < AlliesList.size(); b++)
  {
  	AlliesList[b]->setX(playerobject->getX() - 25);
  	AlliesList[b]->setY(playerobject->getY());
  	AlliesList[b]->move();
  	if(AlliesList[b]->count > 0)
  	{
  	  AlliesList[b]->count--;
  	}
  	if(AlliesList[b]->count == 0)
  	{
  	  PlayerBullet *tempAB = new PlayerBullet(AlliesBulletPixMap, AlliesList[b]->getX()+5, AlliesList[b]->getY()-20);
          PlayerBulletList.push_back(tempAB);
          scene->addItem(tempAB);
          AlliesList[b]->count = AlliesList[b]->getFiringRate();
        }
  }
  if(pbulletcount > 0)
  {
    pbulletcount--;
  }  
  
  if(space == true && pbulletcount == 0)
  {
    PlayerBullet *tempPB = new PlayerBullet(PlayerBulletPixMap, playerobject->getX()+8, playerobject->getY()-20);
    PlayerBulletList.push_back(tempPB);
    scene->addItem(tempPB);
    pbulletcount = 10;
  }

  
  
  
}

/*void MainWindow::show() {
  //This is how we get our view displayed.
  timer->start();
  view->show();
}*/

//hide();

void MainWindow::keyPressEvent(QKeyEvent *e){

	switch(e->key()){
	case Qt::Key_Left:
	  left = true;
	  break;
	case Qt::Key_Right:
	  right = true;
	  break;
	case Qt::Key_Up:
	  up = true;
	  //playerobject->setY(playerobject->getY()-5);
	  break;
	case Qt::Key_Down:
	  //playerobject->setY(playerobject->getY()+5);
	  down = true;
	  break;
	case Qt::Key_Space:
	  space = true;
	  break;	  
	}
	
	/*if(e->key() == Qt::Key_Left)
	{
	  playerobject->setX(playerobject->getX()-5);
	}
	else if(e->key() == Qt::Key_Right)
	{
	  playerobject->setY(playerobject->getX()+5);
	}
	if(e->key() == Qt::Key_Up)
	  playerobject->setX(playerobject->getY()+5);
	else if(e->key() == Qt::Key_Down)
	  playerobject->setY(playerobject->getY()-5);*/
	
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
  
	switch(e->key()) {
  	case Qt::Key_Left:
	left = false;
	break;
  	case Qt::Key_Right:
	right = false;
	break;
  	case Qt::Key_Up:
	up = false;
	break;
  	case Qt::Key_Down:
	down = false;
	break;
	case Qt::Key_Space:
	space = false;
	break;
	}
}

