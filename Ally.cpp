#include "Ally.h"


Ally::Ally(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
  x = nx;
  y = ny;
  vX = 0;
  vY = 0;
  FR = 20;
  count = FR;
  pixMap = pm;
  this->setPixmap(*pixMap);
}

void Ally::setvY(int nvY)
{
  vY = nvY;
}
void Ally::move()
{
  setPos(x,y);
}

void Ally::setX(int nx)
{
  x = nx;
}

int Ally::getX()
{
  return x;
}

int Ally::getY()
{
  return y;
}

void Ally::setY(int ny)
{
  y = ny;
}

void Ally::setFiringRate(int nFR)
{
  FR = nFR;
  count = FR;
}

int Ally::getFiringRate()
{
  return FR;
}
