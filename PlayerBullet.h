#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H
#include "Thing.h"
#include <QGraphicsPixmapItem>

/** A basic Player Bullet Class. It spawns from the player when the player presses space at a set interval. It destroys enemies upon collision.
@author Wayne Chi */
class PlayerBullet: public Thing {
public:
  /** Basic Constructor. Creates the image and sets X and Y */
  PlayerBullet(QPixmap *pm, int nx, int ny);
  /** Defines the movement of the PlayerBullet */
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
