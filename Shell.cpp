#include "Shell.h"


Shell::Shell(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
  x = nx;
  y = ny;
  vX = -10;
  vY = -1;
  pixMap = pm;
  this->setPixmap(*pixMap);
}


void Shell::move()
{
  x+=vX;
  y+=vY;
  setPos(x,y);
}

void Shell::setX(int nx)
{
  x = nx;
}

int Shell::getX()
{
  return x;
}

int Shell::getY()
{
  return y;
}

void Shell::setY(int ny)
{
  y = ny;
}
