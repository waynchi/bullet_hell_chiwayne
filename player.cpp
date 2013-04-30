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
    y-=5;
    if(down)
    y+=5;
}
void Player::move()
{
  if(x<=-250)
  {
    x = -250;
  }
  if(y >=250-35)
  {
    y = 250-35;
  }
  if(y <= -250)
  {
    y = -250;
  }
  if(x >= 250-30)
  {
    x = 250-30;
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
