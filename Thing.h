#ifndef THING_H
#define THING_H

/** The Parent class for all the objects in the game. It is abstract 
@author Wayne Chi */

#include <QGraphicsPixmapItem>
class Thing: public QGraphicsPixmapItem{
public:
  /** Basic Constructor. Creates the image and sets X and Y */
  Thing(QPixmap *pm, int nx, int ny);
  /** Basic move function. Can be changed for each object */
  virtual void move() = 0;
private:
  int x;
  int y;
  int vX;
  int vY;
  QPixmap *pixMap;
};


#endif
