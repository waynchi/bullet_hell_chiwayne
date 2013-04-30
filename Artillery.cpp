#include "Artillery.h"


Artillery::Artillery(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
  x = nx;
  y = ny;
  vX = 0;
  vY = 2;
  FR = 5;
  pixMap = pm;
  this->setPixmap(*pixMap);
}

void Artillery::setvY(int nvY)
{
  vY = nvY;
}
void Artillery::move()
{
  x+=vX;
  y+=vY;
  setPos(x,y);
}

void Artillery::setX(int nx)
{
  x = nx;
}

int Artillery::getX()
{
  return x;
}

int Artillery::getY()
{
  return y;
}

void Artillery::setY(int ny)
{
  y = ny;
}

void Artillery::setFiringRate(int nFR)
{
  FR = nFR;
  count = 0;
}

int Artillery::getFiringRate()
{
  return FR;
}
