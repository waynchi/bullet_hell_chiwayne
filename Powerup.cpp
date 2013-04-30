#include "Powerup.h"


Powerup::Powerup(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
  x = nx;
  y = ny;
  vX = 0;
  vY = 3;
  pixMap = pm;
  this->setPixmap(*pixMap);
}


void Powerup::move()
{
  x+=vX;
  y+=vY;
  setPos(x,y);
}

void Powerup::setX(int nx)
{
  x = nx;
}

int Powerup::getX()
{
  return x;
}

int Powerup::getY()
{
  return y;
}

void Powerup::setY(int ny)
{
  y = ny;
}
