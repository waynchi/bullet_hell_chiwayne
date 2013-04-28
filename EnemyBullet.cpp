#include "EnemyBullet.h"


EnemyBullet::EnemyBullet(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
  x = nx;
  y = ny;
  vX = 0;
  vY = 10;
  pixMap = pm;
  this->setPixmap(*pixMap);
}


void EnemyBullet::move()
{
  x+=vX;
  y+=vY;
  setPos(x,y);
}

void EnemyBullet::setX(int nx)
{
  x = nx;
}

int EnemyBullet::getX()
{
  return x;
}

int EnemyBullet::getY()
{
  return y;
}

void EnemyBullet::setY(int ny)
{
  y = ny;
}
