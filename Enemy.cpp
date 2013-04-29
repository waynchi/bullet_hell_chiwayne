#include "Enemy.h"


Enemy::Enemy(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
  x = nx;
  y = ny;
  vX = 0;
  vY = 5;
  FR = 5;
  pixMap = pm;
  this->setPixmap(*pixMap);
}

void Enemy::setvY(int nvY)
{
  vY = nvY;
}
void Enemy::move()
{
  x+=vX;
  y+=vY;
  setPos(x,y);
}

void Enemy::setX(int nx)
{
  x = nx;
}

int Enemy::getX()
{
  return x;
}

int Enemy::getY()
{
  return y;
}

void Enemy::setY(int ny)
{
  y = ny;
}

void Enemy::setFiringRate(int nFR)
{
  FR = nFR;
  count = 0;
}

int Enemy::getFiringRate()
{
  return FR;
}
