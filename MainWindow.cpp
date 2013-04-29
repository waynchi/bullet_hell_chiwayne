#include "MainWindow.h"

MainWindow::MainWindow()  {
  //We need a scene and a view to do graphics in QT
  left = false;
  right = false;
  up = false;
  down = false;
  space = false;
  pbulletcount = 0;
  enemycount = 10;
  lives = 3;
  timercount = 0;
  interval = 50;
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
 
  
  //Ally
 
 
  
  timer = new QTimer(this);
  timer2 = new QTimer(this);
  timer2->setInterval(1000);
  timer->setInterval(interval);
  timer->start();
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
  connect(timer2, SIGNAL(timeout()), this, SLOT(handleDeath()));
}

MainWindow::~MainWindow() {

}
void MainWindow::handleDeath()
{
  for(unsigned int a = 0; a < EnemyBulletList.size(); a++)
  {
    delete EnemyBulletList[a];
  }
  for(unsigned int b = 0; b < PlayerBulletList.size(); b++)
  {
    delete PlayerBulletList[b];
  }
  for(unsigned int c = 0; c < AlliesList.size(); c++)
  {
    delete AlliesList[c];
  }
  for(unsigned int d = 0; d < EnemyList.size(); d++)
  {
    delete EnemyList[d];
  }
  Powerup *tempP = PowerupObject;
  delete tempP;
  PowerupObject = NULL;
  EnemyBulletList.clear();
  PlayerBulletList.clear();
  AlliesList.clear();
  EnemyList.clear();
  interval = 50;
  timer->setInterval(interval);
  timercount = 0;
  timer->start();
  timer2->stop();
}
  
void MainWindow::handleTimer()
{
  setFocus();
  timercount++;
  if(timercount == 125 && interval > 10)
  {
    interval -= 5;
    timercount = 0;
    timer->setInterval(interval);
    cout << "making faster!" << interval << endl;
  }
  playerobject->change(left, right, up, down);
  playerobject->move();
  if(PowerupObject != NULL)
  {
    PowerupObject->move();
  }
  for (unsigned int i = 0; i < PlayerBulletList.size(); i++)
  {
  	if(PlayerBulletList[i]!=NULL)
  	{
  	PlayerBulletList[i]->move();
  	}
  }
  for (unsigned int j = 0; j < EnemyList.size(); j++)
  {
    if(EnemyList[j] != NULL)
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
  }
  for (unsigned int k = 0; k < EnemyBulletList.size(); k++)
  {
  	EnemyBulletList[k]->move();
  }
  for (unsigned int b = 0; b < AlliesList.size(); b++)
  {
  	if(b == 0)
  	{
  		AlliesList[b]->setX(playerobject->getX() - 35);
  		AlliesList[b]->setY(playerobject->getY());
  		AlliesList[b]->move();
  	}
  	if(b == 1)
  	{
  		AlliesList[b]->setX(playerobject->getX() + 55);
  		AlliesList[b]->setY(playerobject->getY());
  		AlliesList[b]->move();
   	}
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
  if(enemycount > 0)
  {
    enemycount--;
  }
  if(enemycount == 0)
  {
    for (int ii = 0; ii < rand()%4 +1 ; ii++)
    {
      int enemyspawn = (rand() % 570) - 300;
      Enemy *tempE = new Enemy(EnemyPixMap, enemyspawn, -360 - (rand()%50));
      tempE->setvY(rand()%6 + 2);
      tempE->setFiringRate(rand()%20 +40);
      EnemyList.push_back(tempE);
      scene->addItem(tempE);
    }
    if(rand() %3 == 1)
    {
      Enemy *tempFE = new Enemy(EnemyPixMap, playerobject->getX(), -360);
      tempFE->setvY(rand()%6 + 2);
      tempFE->setFiringRate(rand()%20 +40);
      EnemyList.push_back(tempFE);
      scene->addItem(tempFE);
    }
    enemycount = 30;
  }
  
  //collisions
  //Player Bullet Collision
  for(unsigned  int a = 0; a < PlayerBulletList.size(); a++)
  {
    PlayerBullet *itemA = PlayerBulletList[a];
    if(itemA != NULL)
    {
    for(unsigned int aa = 0; aa < EnemyList.size(); aa++)
    {
      Enemy *itemB = EnemyList[aa];
      if(itemA->collidesWithItem(itemB))
      {
        if(itemB !=NULL)
        {
          if(PowerupObject == NULL)
          {
            if(rand()%20 == 10)
            {
              PowerupObject = new Powerup(PowerupPixMap, EnemyList[aa]->getX(),EnemyList[aa]->getY());
              scene->addItem(PowerupObject);
            }
          }
          delete itemA;
    	  PlayerBulletList[a] = NULL;
    	  delete itemB;
    	  EnemyList[aa] = NULL;    	
          break;
        }
      }
    }
    }
  }
  //Powerup Collision
  if(PowerupObject != NULL)
  {
  if(PowerupObject->collidesWithItem(playerobject))
  {
      cout << AlliesList.size() << endl;
      if(AlliesList.size() == 1)
      {
        Ally *tempA = new Ally(AlliesPixMap, playerobject->getX() + 55 , playerobject->getY());
  	AlliesList.push_back(tempA);
  	scene->addItem(tempA);
      }
      if(AlliesList.size() == 0)
      {
         Ally *tempA = new Ally(AlliesPixMap, playerobject->getX() - 35 , playerobject->getY());
  	 AlliesList.push_back(tempA);
  	 scene->addItem(tempA);
      }
  
    Powerup *tempP = PowerupObject;
    delete tempP;
    PowerupObject = NULL;
  }
  }
 
 
  //Enemy Bullet collision
  bool tester = true;
  for(unsigned int b = 0; b < EnemyBulletList.size(); b++)
  {
    EnemyBullet *itemC = EnemyBulletList[b];
    if(itemC != NULL)
    {
      Player *itemD = playerobject;
      if(itemC->collidesWithItem(itemD))
      {
        delete itemC;
        EnemyBulletList[b] = NULL;
        timer->stop();
        timer2->start();
        lives--;
        tester = false;
        break;
      }
    }
  }
  if(tester)
  {
  //Enemy Collision
  for(unsigned int c = 0; c < EnemyList.size(); c++)
  {
    Enemy *itemE = EnemyList[c];
    if(itemE != NULL)
    {
      Player *itemF = playerobject;
      if(itemE->collidesWithItem(itemF))
      {
        delete itemE;
        EnemyList[c] = NULL;
        timer->stop();
        timer2->start();
        lives--;
        break;
      }
    }
  }
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

