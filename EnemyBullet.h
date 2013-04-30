#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "Thing.h"
#include <QGraphicsPixmapItem>

using namespace std;
/** A basic EnemyBullet class. This is spawned from the enemy at a random interval. It will destroy (take away a life) from the player upon collision with it.
@author Wayne Chi */
class EnemyBullet: public Thing {
public:
  /** Basic Constructor. Creates the image and sets X and Y */
  EnemyBullet(QPixmap *pm, int nx, int ny);
  /** Defines the movement of the EnemyBullet */
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
  
  
private:
  int x;
  int y;
  int vX;
  int vY;
  QPixmap *pixMap;
  QGraphicsPixmapItem *graphicsPixMap;
};



#endif
