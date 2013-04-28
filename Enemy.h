#ifndef ENEMY_H
#define ENEMY_H
#include "Thing.h"
#include <QGraphicsPixmapItem>

using namespace std;
class Enemy: public Thing {
public:
  Enemy(QPixmap *pm, int nx, int ny);
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
