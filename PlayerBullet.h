#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H
#include "Thing.h"
#include <QGraphicsPixmapItem>
class PlayerBullet: public Thing {
public:
  PlayerBullet(QPixmap *pm, int nx, int ny);
  void move();
  void setX(int nx);
  int getX();
  int getY();
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
