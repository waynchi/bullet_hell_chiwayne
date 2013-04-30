#ifndef ENEMY_H
#define ENEMY_H
#include "Thing.h"
#include <QGraphicsPixmapItem>

using namespace std;

/** The Enemy Class. It first bullets and constantly moves downward. It also spawns randomly, and will destroy the Player upon contact
@author Wayne Chi */
class Enemy: public Thing {
public:
  /** Basic Constructor. Creates the image and sets X and Y */
  Enemy(QPixmap *pm, int nx, int ny);
  /** Defines the movement of the Enemy */
  void move();
  /** Sets X */
  void setX(int nx);
  /** Gets X 
  @return X value*/
  int getX();
  /** Gets Y 
  @return Y Value*/
  int getY();
  /** Sets Y */
  void setY(int ny);
  /** Sets Y incremental (Y velocity) */
  void setvY(int nvY);
  /** Sets the Firing Rate of the enemy */
  void setFiringRate(int nFR);
  /** Gets the Firing Rate of the enemy 
  @return Firing Rate */
  int getFiringRate();
  /** A public variable that is used to count for the Firing rate */
  int count; 
  
  
private:
  int x;
  int y;
  int vX;
  int vY;
  int FR;
  QPixmap *pixMap;
  QGraphicsPixmapItem *graphicsPixMap;
};



#endif
