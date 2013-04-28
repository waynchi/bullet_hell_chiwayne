#include "PlayerBullet.h"


PlayerBullet::PlayerBullet(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
  x = nx;
  y = ny;
  vX = 0;
  vY = -10;
  pixMap = pm;
  this->setPixmap(*pixMap);
}


void PlayerBullet::move()
{
  x+=vX;
  y+=vY;
  setPos(x,y);
}

void PlayerBullet::setX(int nx)
{
  x = nx;
}

int PlayerBullet::getX()
{
  return x;
}

int PlayerBullet::getY()
{
  return y;
}

void PlayerBullet::setY(int ny)
{
  y = ny;
}
