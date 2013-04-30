#include "Background.h"


Background::Background(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
  x = nx;
  y = ny;
  vX = 0;
  vY = 2;
  pixMap = pm;
  this->setPixmap(*pixMap);
}

void Background::setvY(int nvY)
{
  vY = nvY;
}
void Background::move()
{
  x+=vX;
  y+=vY;
  setPos(x,y);
}

void Background::setX(int nx)
{
  x = nx;
}

int Background::getX()
{
  return x;
}

int Background::getY()
{
  return y;
}

void Background::setY(int ny)
{
  y = ny;
}
