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
  score = 0;
  PowerupObject = NULL;
  ArtilleryObject = NULL;
  bound = new QRectF(-250,-250,500,500);
  scene = new QGraphicsScene();
  view = new QGraphicsView( scene );
  view->setFixedSize(500, 500);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setSceneRect(*bound); 
  mainLayout = new QVBoxLayout;
  setLayout(mainLayout);
  setFocus();
 
  //title window
  QHBoxLayout *HBoxLayout = new QHBoxLayout;
  startbutton = new QPushButton;
  exitbutton = new QPushButton;
  QFormLayout *formLayout = new QFormLayout;
  startbutton = new QPushButton("&Start");
  exitbutton = new QPushButton("&Quit");
  titleLayout = new QVBoxLayout;
  HBoxLayout->addWidget(startbutton);
  HBoxLayout->addWidget(exitbutton);
  
  nameedit = new QLineEdit;
  QLabel *nameLabel = new QLabel("name");
  
  formLayout->addRow(nameLabel, nameedit);
  titleLayout->addLayout(HBoxLayout);
  titleLayout->addLayout(formLayout);
  mainLayout->addLayout(titleLayout);
  mainLayout->addWidget(view);
  
  
  playerpixmap = new QPixmap("images/Player.png");
  PlayerBulletPixMap = new QPixmap("images/PlayerBulletActual.png");
  EnemyPixMap = new QPixmap("images/Enemy.png");
  EnemyBulletPixMap = new QPixmap("images/EnemyBulletActual.png");
  PowerupPixMap = new QPixmap("images/Powerup.png");
  AlliesPixMap = new QPixmap("images/AlliesActual.png");
  AlliesBulletPixMap = new QPixmap("images/AlliedBullet.png");
  ArtilleryPixMap = new QPixmap("images/Artillery.png");
  ShellPixMap = new QPixmap("images/ball.png");
  BackgroundPixMap = new QPixmap("images/Background.png");
  BackgroundPixMap2 = new QPixmap("images/Background2.png");
  BackgroundPixMap3 = new QPixmap("images/background3.png");
  
  
  
  
  timer = new QTimer(this);
  timer2 = new QTimer(this);
  timer2->setInterval(1000);
  timer->setInterval(interval);
 
  connect(startbutton, SIGNAL(clicked()), this, SLOT(start()));
  connect(exitbutton, SIGNAL(clicked()), this, SLOT(quit()));
  connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
  connect(timer2, SIGNAL(timeout()), this, SLOT(handleDeath()));
  
}

MainWindow::~MainWindow() {
 
}

void MainWindow::start()
{
   if(timer->isActive())
   {
     timer2->start();
     lives=3;
     level = 0;
     levelup();
     score = 0;
     level = 1;

     timer->stop();
   }
   else if(!timer2->isActive())
   {
     scene->clear();
     score = 0;
     lives = 3;
     timer->start();
     level = 1;
     BackgroundObject1 = new Background(BackgroundPixMap, -250, -250);
     scene->addItem(BackgroundObject1);
     BackgroundObject2 = new Background(BackgroundPixMap, -250, -750);
     scene->addItem(BackgroundObject2);
     BackgroundObject3 = new Background(BackgroundPixMap, -250, -1250);
     scene->addItem(BackgroundObject3);
     playerobject = new Player(playerpixmap, 0,0);
     if(nameedit->text().isEmpty())
     {     scoreword = new QGraphicsSimpleTextItem("NO NAME");
     	   name = "NO NAME";
     }
     else{
     	   scoreword = new QGraphicsSimpleTextItem(nameedit->text());
     	   name = nameedit->text().toStdString();
     }
     
     scoreword->setPos(-240, -245);
     scoretext = new QGraphicsSimpleTextItem("0");
     scoretext->setPos(-240, -225);
     livesword = new QGraphicsSimpleTextItem("LIVES");
     livesword->setPos(210, -245);
     livestext = new QGraphicsSimpleTextItem("3");
     livestext->setPos(210, -225);
     scene->addItem(playerobject);
     scene->addItem(scoreword);
     scene->addItem(scoretext);
     scene->addItem(livestext);
     scene->addItem(livesword);
   }

   
}

void MainWindow::quit()
{
  exit(1);
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
  for(unsigned int e = 0; e < ShellList.size(); e++)
  {
    delete ShellList[e];
  }
  Powerup *tempP = PowerupObject;
  delete tempP;
  PowerupObject = NULL;
  Artillery *tempArt = ArtilleryObject;
  ArtilleryObject = NULL;
  delete tempArt;
  EnemyBulletList.clear();
  PlayerBulletList.clear();
  AlliesList.clear();
  EnemyList.clear();
  ShellList.clear();
  interval = 50;
  timer->setInterval(interval);
  timercount = 0;
  if(lives == 0)
  {
    QGraphicsSimpleTextItem *gameover = new QGraphicsSimpleTextItem("GAME OVER");
    livestext->setText("0");
    gameover->setPos(-50,0);
    scene->addItem(gameover);
    Player *tempPla = playerobject;
    playerobject = NULL;
    delete tempPla;
    //handling highscores
    ifstream ifile("highscore.txt");
    ofstream myfile;
    vector<int> highscore;
    vector<string> highscoren;
    int i = 0;
    string line;
    string line2;
    stringstream ss;
    if(ifile)
    {
    	if( ifile.is_open())
    	{
    	  while(ifile.good())
    	  {
    	    getline(ifile,line);
    	    highscoren.push_back(line);
    	    getline (ifile,line2);
    	    i = atoi(line2.c_str());
    	    highscore.push_back(i);
    	  }
    	}
  	myfile.open("highscore.txt");
   	for(unsigned int j = 0; j < highscoren.size()-1; j++)
  	{
        if(score > highscore[j])
        {
          myfile << name;
          myfile << "\n";
     	  myfile << score;
     	  myfile << "\n";
          score = 0;
          myfile << highscoren[j];
          myfile << "\n";          
          myfile << highscore[j];
          myfile << "\n";
        }
        else
        {
          myfile << highscoren[j];
          myfile << "\n";
          myfile << highscore[j];
          myfile << "\n";
        }
     }
     if(score == 0)
     {
     }
     else
     {
       myfile << name;
       myfile << "\n";
       myfile << score;
     }
   }
   else
   {
     myfile.open("highscore.txt");
     myfile << name;
     myfile << "\n";
     myfile << score;
   }
   myfile.close();
  }
  else
  timer->start();
  timer2->stop();
}
  
void MainWindow::levelup()
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
  for(unsigned int e = 0; e < ShellList.size(); e++)
  {
    delete ShellList[e];
  }
  Powerup *tempP = PowerupObject;
  delete tempP;
  Player *tempPla = playerobject;
  playerobject = NULL;
  delete tempPla;
  PowerupObject = NULL;
  Artillery *tempArt = ArtilleryObject;
  ArtilleryObject = NULL;
  delete tempArt;
  EnemyBulletList.clear();
  PlayerBulletList.clear();
  AlliesList.clear();
  EnemyList.clear();
  ShellList.clear();
  interval = 50;
  timer->setInterval(interval);
  timercount = 0;
  Background* tempBack = BackgroundObject1;
  delete tempBack;
  tempBack = BackgroundObject2;
  delete tempBack;
  tempBack = BackgroundObject3;
  delete tempBack;
  scene->clear();
  if(level == 0)
  {
  BackgroundObject1 = new Background(BackgroundPixMap, -250, -250);
  scene->addItem(BackgroundObject1);
  BackgroundObject2 = new Background(BackgroundPixMap, -250, -750);
  scene->addItem(BackgroundObject2);
  BackgroundObject3 = new Background(BackgroundPixMap, -250, -1250);
  scene->addItem(BackgroundObject3);
  }
  if(level == 1)
  {
  BackgroundObject1 = new Background(BackgroundPixMap2, -250, -250);
  scene->addItem(BackgroundObject1);
  BackgroundObject2 = new Background(BackgroundPixMap2, -250, -750);
  scene->addItem(BackgroundObject2);
  BackgroundObject3 = new Background(BackgroundPixMap2, -250, -1250);
  scene->addItem(BackgroundObject3);
  }
  if(level == 2)
  {
  BackgroundObject1 = new Background(BackgroundPixMap3, -250, -250);
  scene->addItem(BackgroundObject1);
  BackgroundObject2 = new Background(BackgroundPixMap3, -250, -750);
  scene->addItem(BackgroundObject2);
  BackgroundObject3 = new Background(BackgroundPixMap3, -250, -1250);
  scene->addItem(BackgroundObject3);
  }  
  playerobject = new Player(playerpixmap, 0,0);
  scene->addItem(playerobject);
  if(nameedit->text().isEmpty())
     {     scoreword = new QGraphicsSimpleTextItem("NO NAME");
     	   name = "NO NAME";
     }
     else{
     	   scoreword = new QGraphicsSimpleTextItem(nameedit->text());
     	   name = nameedit->text().toStdString();
     }
     
     scoreword->setPos(-240, -245);
     scoretext = new QGraphicsSimpleTextItem("0");
     scoretext->setPos(-240, -225);
     livesword = new QGraphicsSimpleTextItem("LIVES");
     livesword->setPos(210, -245);
     livestext = new QGraphicsSimpleTextItem("3");
     livestext->setPos(210, -225);
     scene->addItem(scoreword);
     scene->addItem(scoretext);
     scene->addItem(livestext);
     scene->addItem(livesword);
     timer->start();
}
void MainWindow::handleTimer()
{
  score+=10;
  stringstream ss, ll;
  string s,l;
  ss << score;
  s = ss.str();
  scoretext->setText(s.c_str());
  ss.clear();
  ll << lives;
  l = ll.str();
  livestext->setText(l.c_str());
  ll.clear();
  if(timercount%25 == 0)
  {
    setFocus();
  }
  timercount++;
  if(timercount == 150 && interval > 10)
  {
    interval -= 5;
    timercount = 0;
    timer->setInterval(interval);
  }
  if(score >= 20000 && level == 1)
  {
    timer->stop();
    levelup();
    level = 2;
  }
  if(score >= 50000 && level == 2)
  {
    timer->stop();
    levelup();
    level = 3;
  }
  BackgroundObject1->move();
  BackgroundObject2->move();
  BackgroundObject3->move();
  if(BackgroundObject1->getY() == 250)
    BackgroundObject1->setY(-1250);
  if(BackgroundObject2->getY() == 250)
    BackgroundObject2->setY(-1250);
  if(BackgroundObject3->getY() == 250)
    BackgroundObject3->setY(-1250);
  
  playerobject->change(left, right, up, down);
  playerobject->move();
  if(PowerupObject != NULL)
  {
    PowerupObject->move();
    if(PowerupObject->getY()>350)
    {
      Powerup *tempPower = PowerupObject;
      delete tempPower;
      PowerupObject = NULL;
    }
  }
  for (unsigned int i = 0; i < PlayerBulletList.size(); i++)
  {
  	if(PlayerBulletList[i]!=NULL)
  	{
  	PlayerBulletList[i]->move();
  	if(PlayerBulletList[i]->getY() < -350)
  	{
  	  PlayerBullet *tempPlayerBullet = PlayerBulletList[i];
  	  delete tempPlayerBullet;
  	  PlayerBulletList[i] = NULL;
  	}
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
  	  EnemyBullet *tempEB = new EnemyBullet(EnemyBulletPixMap, EnemyList[j]->getX()+5, EnemyList[j]->getY()+10);
  	  EnemyBulletList.push_back(tempEB);
    	  scene->addItem(tempEB);
    	  EnemyList[j]->count = EnemyList[j]->getFiringRate();
    	}
        if(EnemyList[j]->getY() > 350)
  	{
  	  Enemy *temporaryE = EnemyList[j];
  	  delete temporaryE;
  	  EnemyList[j] = NULL;
  	}
    }
    
  }
  for (unsigned int k = 0; k < EnemyBulletList.size(); k++)
  {
  	if(EnemyBulletList[k] != NULL)
  	{
  	  EnemyBulletList[k]->move();
  	  if(EnemyBulletList[k]->getY() > 350)
  	  {
  	    EnemyBullet *temporaryEB = EnemyBulletList[k];
  	    delete temporaryEB;
  	    EnemyBulletList[k] = NULL;
   	  }
   	}
  }
  
  for (unsigned int b = 0; b < AlliesList.size(); b++)
  {
  	if(b == 0)
  	{
  		AlliesList[b]->setX(playerobject->getX() - 25);
  		AlliesList[b]->setY(playerobject->getY());
  		AlliesList[b]->move();
  	}
  	if(b == 1)
  	{
  		AlliesList[b]->setX(playerobject->getX() + 45);
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
    PlayerBullet *tempPB = new PlayerBullet(PlayerBulletPixMap, playerobject->getX()+5, playerobject->getY()-10);
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
    for (int ii = 0; ii < (rand()%3)*level +1 ; ii++)
    {
      int enemyspawn = (rand() % 475) - 250;
      Enemy *tempE = new Enemy(EnemyPixMap, enemyspawn, -330 - (rand()%50));
      tempE->setvY(rand()%6 + 2);
      tempE->setFiringRate(rand()%20 +40);
      EnemyList.push_back(tempE);
      scene->addItem(tempE);
    }
    if(rand() %3 == 1)
    {
      Enemy *tempFE = new Enemy(EnemyPixMap, playerobject->getX(), -330);
      tempFE->setvY(rand()%6 + 2);
      tempFE->setFiringRate(rand()%20 +40);
      EnemyList.push_back(tempFE);
      scene->addItem(tempFE);
    }
    enemycount = 30;
  }
  if(ArtilleryObject == NULL)
  {
    if(rand()%20 == 5)
    {
      ArtilleryObject = new Artillery(ArtilleryPixMap, 180, -330);
      ArtilleryObject->setFiringRate(rand()%10 +30);
      scene->addItem(ArtilleryObject);
    }
  }
  if(ArtilleryObject != NULL)
  {
    ArtilleryObject->move();
    if(ArtilleryObject->getY() > 260)
    {
      Artillery *tempArt = ArtilleryObject;
      ArtilleryObject = NULL;
      delete tempArt;
    }
    else
    {
        if(ArtilleryObject->count > 0)
  	{
  	  ArtilleryObject->count--;
  	}
  	if(ArtilleryObject->count == 0)
  	{
  	  Shell *tempShell = new Shell(ShellPixMap, ArtilleryObject->getX()+10, ArtilleryObject->getY());
    	  scene->addItem(tempShell);
    	  ShellList.push_back(tempShell);
    	  ArtilleryObject->count = ArtilleryObject->getFiringRate();
    	}
    }
  }
  for (unsigned int s = 0; s < ShellList.size(); s++)
  {
  	if(ShellList[s] != NULL)
  	{
  	  ShellList[s]->move();
  	  if(ShellList[s]->getX() < -300)
  	  {
  	    Shell *temporaryS = ShellList[s];
  	    delete temporaryS;
  	    ShellList[s] = NULL;
  	  }
  	}
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
          score +=1000;
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
      if(AlliesList.size() == 1)
      {
        Ally *tempA = new Ally(AlliesPixMap, playerobject->getX() + 45 , playerobject->getY());
  	AlliesList.push_back(tempA);
  	scene->addItem(tempA);
      }
      if(AlliesList.size() == 0)
      {
         Ally *tempA = new Ally(AlliesPixMap, playerobject->getX() - 25 , playerobject->getY());
  	 AlliesList.push_back(tempA);
  	 scene->addItem(tempA);
      }
    score +=10000;
    Powerup *tempP = PowerupObject;
    delete tempP;
    PowerupObject = NULL;
  }
  }
 
 
  //Enemy Bullet collision
  bool tester = true,tester2 = true;
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
        tester2 = false;
        break;
      }
    }
  }
  }
  if(tester2)
  {
  //Artillery Bullet Collision
  for(unsigned int d = 0; d < ShellList.size(); d++)
  {
    Shell *itemG = ShellList[d];
    if(itemG != NULL)
    {
      Player *itemH = playerobject;
      if(itemG->collidesWithItem(itemH))
      {
        delete itemG;
        ShellList[d] = NULL;
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
	case Qt::Key_Escape:
	  if(!timer2->isActive())
	  {
	    if(timer->isActive())
	      timer->stop();
	    else
	      timer->start();
	  }
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

