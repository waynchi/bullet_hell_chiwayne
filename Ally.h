#ifndef ALLIES_H
#define ALLIES_H
#include "Thing.h"
#include <QGraphicsPixmapItem>

using namespace std;
class Ally: public Thing {
public:
  Ally(QPixmap *pm, int nx, int ny);
  void move();
  void setX(int nx);
  int getX();
  int getY();
  void setY(int ny);
  void setvY(int nvY);
  void setFiringRate(int nFR);
  int getFiringRate();
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
