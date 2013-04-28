
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
#include "cstdlib"
#include <QKeyEvent>
#include <QMouseEvent>

using namespace std;

class MainWindow : public QWidget {
	Q_OBJECT
	
public:
  explicit MainWindow();
  ~MainWindow();
  //void show();
  
  
protected:
  void keyPressEvent(QKeyEvent *e);
 // void mousePressEvent(QMouseEvent *e);
  void keyReleaseEvent(QKeyEvent *e);
  
private:
    /** Scene of main game. */
    QGraphicsScene *scene;
    /** View of main game. */
    QGraphicsView *view;
    /** Timer to help with animation. */
    QTimer *timer;
    /** The window that contains everything. */
    QWidget *window;
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
    
    QRectF *bound;
    /** Player Object */
    Player *playerobject;
    /** Power up Object */
    Powerup *PowerupObject;
    
    QVBoxLayout *mainLayout;
    
    /** key presses */
    bool left;
    bool right;
    bool down;
    bool up;
    bool space;
    
    /** counts */
    int pbulletcount;
    
    //Vectors
    /** vector holding Player Bullets */
    vector<PlayerBullet*> PlayerBulletList;
    /** vector holding Enemies */
    vector<Enemy*> EnemyList;
    /** vector holding Enemy Bullet */
    vector<EnemyBullet*> EnemyBulletList;
    /** vector holding Allies */
    vector<Ally*> AlliesList;
public slots:
  void handleTimer();

};

#endif
