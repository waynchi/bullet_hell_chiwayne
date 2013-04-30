#ifndef SHELL_H
#define SHELL_H
#include "Thing.h"
#include <QGraphicsPixmapItem>

using namespace std;
/** An Artillery Shell that is fired from the Artillery. It will travel to the left, and slightly up. It destroys the player (takes away a life) upon contact.
@author Wayne Chi */
class Shell: public Thing {
public:
  /** Basic Constructor. Creates the image and sets X and Y */
  Shell(QPixmap *pm, int nx, int ny);
  /** Defines the movement of the Shell */
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
