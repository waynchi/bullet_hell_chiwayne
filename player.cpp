#include "player.h"


Player::Player(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
  x = nx;
  y = ny;
  pixMap = pm;
  this->setPixmap(*pixMap);
}

void Player::change(bool left, bool right, bool up, bool down)
{

    if(left)
    x-=10;
    if(right)
    x+=10;
    if(up)
    y-=10;
    if(down)
    y+=5;
}
void Player::move()
{
  if(x<=-300)
  {
    x = -300;
  }
  if(y >=300-65)
  {
    y = 300-65;
  }
  if(y <= -300)
  {
    y = -300;
  }
  if(x >= 300-55)
  {
    x = 300-55;
  }
  setPos(x,y);
}

void Player::setX(int nx)
{
  x = nx;
}

int Player::getX()
{
  return x;
}

int Player::getY()
{
  return y;
}

void Player::setY(int ny)
{
  y = ny;
}
