#ifndef POWERUP_H
#define POWERUP_H
#include "Thing.h"
#include <QGraphicsPixmapItem>

using namespace std;
/** A Powerup that randomly drops from a destroyed enemy. It gives the player an ally and points upon collection.
@author Wayne Chi*/
class Powerup: public Thing {
public:
  /** Basic Constructor. Creates the image and sets X and Y */
  Powerup(QPixmap *pm, int nx, int ny);
  /** Defines the movement of the Powerup */
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
  
  
private:
  int x;
  int y;
  int vX;
  int vY;
  QPixmap *pixMap;
  QGraphicsPixmapItem *graphicsPixMap;
};



#endif
