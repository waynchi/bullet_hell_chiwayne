#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "Thing.h"
#include <QGraphicsPixmapItem>

using namespace std;
class EnemyBullet: public Thing {
public:
  EnemyBullet(QPixmap *pm, int nx, int ny);
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
