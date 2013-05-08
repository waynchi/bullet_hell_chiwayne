
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFormLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QMainWindow>
#include <QRectF>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsWidget>
#include <QTimer>
#include <QTimeLine>
#include <QLabel>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QIntValidator>
#include <vector>
#include <QLayout>
#include <QLineEdit>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsItemGroup>
#include <QString>
#include "player.h"
#include "PlayerBullet.h"
#include "Thing.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Ally.h"
#include "Powerup.h"
#include "Artillery.h"
#include "Shell.h"
#include "Background.h"
#include "cstdlib"
#include <QKeyEvent>
#include <QMouseEvent>

using namespace std;

/** The Class that contains everything required to operate the game
@author Wayne Chi */
class MainWindow : public QWidget {
	Q_OBJECT
	
public:
  explicit MainWindow();
  ~MainWindow();
  //void show();
  
  
protected:
  /** Method that allows keyPresses */
  void keyPressEvent(QKeyEvent *e);
  //void mousePressEvent(QMouseEvent *e);
  /** Method that tracks keyReleases */
  void keyReleaseEvent(QKeyEvent *e);
  
private:
    /** Scene of main game. */
    QGraphicsScene *scene;
    /** View of main game. */
    QGraphicsView *view;
    /** Timer to help with animation. */
    QTimer *timer;
    /** Timer to handle player death */
    QTimer *timer2;
    /** Button for starting the game */
    QPushButton *startbutton;
    /** Button for Quitting the game */
    QPushButton *exitbutton;
    /** line for entering the name */
    QLineEdit *nameedit;
    /** Layout for title */
    QVBoxLayout *titleLayout;
    /** Player Pixmap */
    QPixmap *playerpixmap;
    /** Player Bullet Pixmap */
    QPixmap *PlayerBulletPixMap;
    /** Enemy Pixmap */
    QPixmap *EnemyPixMap;
    /** Enemy Bullet Pixmap */
    QPixmap *EnemyBulletPixMap;
    /** Power up Pixmap */
    QPixmap *PowerupPixMap;
    /** Allies Pixmap */
    QPixmap *AlliesPixMap;
    /** Ally Bullet Pixmap */
    QPixmap *AlliesBulletPixMap;
    // Artillery Pixmap
    QPixmap *ArtilleryPixMap;
    // Shell Pixmap
    QPixmap *ShellPixMap;
    // Background Pixmap
    QPixmap *BackgroundPixMap;
    QPixmap *BackgroundPixMap2;
    QPixmap *BackgroundPixMap3;
    
    //level
    int level;
    
    /** The Bound of the game */
    QRectF *bound;
    /** Player Object */
    Player *playerobject;
    /** Power up Object */
    Powerup *PowerupObject;
    // Artillery Object
    Artillery *ArtilleryObject;
    //Background Objects
    Background *BackgroundObject1;
    Background *BackgroundObject2;
    Background *BackgroundObject3;
    
    /** The Main Layout of the game */
    QVBoxLayout *mainLayout;
    
    /** key presses to keep track of */
    bool left, right, down, up, space;
    
    /** counts to keep track of */
    int pbulletcount, enemycount, timercount, interval;
    
    /**player lives count */
    int lives;
    /**player score count */
    int score;
    //name
    string name;
    /**player score text item*/
    QGraphicsSimpleTextItem *scoretext;
    /**score text item */
    QGraphicsSimpleTextItem *scoreword;
    /**player lives text item*/
    QGraphicsSimpleTextItem *livestext;
    /**lives text item */
    QGraphicsSimpleTextItem *livesword;
    
    //Vectors
    /** vector holding Player Bullets */
    vector<PlayerBullet*> PlayerBulletList;
    /** vector holding Enemies */
    vector<Enemy*> EnemyList;
    /** vector holding Enemy Bullet */
    vector<EnemyBullet*> EnemyBulletList;
    /** vector holding Allies */
    vector<Ally*> AlliesList;
    /** vector holding Shells */
    vector<Shell*> ShellList;
    //leveling up;
    void levelup();
    
    
public slots:
  /** handles the main timer */
  void handleTimer();
  /** handles the timer upon dying */
  void handleDeath();
  /** handles the start button getting clicked */
  void start();
  /** quits the game */
  void quit();

};

#endif
