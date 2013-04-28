#ifndef PLAYER_H
#define PLAYER_H
#include "Thing.h"
#include <QGraphicsPixmapItem>
#include <iostream>

using namespace std;
class Player: public Thing {
public:
  Player(QPixmap *pm, int nx, int ny);
  void change(bool left, bool right, bool up, bool down);
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
