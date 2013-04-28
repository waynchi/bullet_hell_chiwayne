#include "Thing.h"


Thing::Thing(QPixmap* pm, int nx, int ny)
{
  pixMap = pm;
  setPixmap(*pm);
  x = nx;
  y = ny;
  setPos(x,y);
}
