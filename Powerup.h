#ifndef POWERUP_H
#define POWERUP_H
#include "Thing.h"
#include <QGraphicsPixmapItem>

using namespace std;
class Powerup: public Thing {
public:
  Powerup(QPixmap *pm, int nx, int ny);
  void move();
  void setX(int nx);
  int getX();
  int getY();
  void setY(int ny);
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
