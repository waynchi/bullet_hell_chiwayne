#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Thing.h"
#include <QGraphicsPixmapItem>

using namespace std;
/** A basic background class that scrolls behind the images. Just for scenery. 
@author Wayne Chi */
class Background: public Thing {
public:
  /** Basic Constructor. Creates the image and sets X and Y */
  Background(QPixmap *pm, int nx, int ny);
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
