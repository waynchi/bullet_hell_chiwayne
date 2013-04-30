#ifndef ALLIES_H
#define ALLIES_H
#include "Thing.h"
#include <QGraphicsPixmapItem>

using namespace std;
/** An Ally class that handles the Ally. The ally spawns next to you (on the right or left) when a powerup is picked up. It fires bullets of its own that will destroy the enemy.
@author Wayne Chi*/
class Ally: public Thing {
public:
  /** Basic Constructor. Creates the image and sets X and Y */
  Ally(QPixmap *pm, int nx, int ny);
  /** Defines the movement of the Ally */
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
  /** Sets the Firing Rate of the Ally */
  void setFiringRate(int nFR);
  /** Gets the Firing Rate of the Ally 
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
