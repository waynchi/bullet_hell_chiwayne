#ifndef PLAYER_H
#define PLAYER_H
#include "Thing.h"
#include <QGraphicsPixmapItem>
#include <iostream>

using namespace std;
/** This is the Player class. It is the ship that the player controls. It loses a life upon collision with an Enemy, enemy bullet, or artillery shell. It can gain allies through powerups. If lives goes to 0. The game is over. 
@author Wayne Chi */
class Player: public Thing {
public:
  /** Basic Constructor. Creates the image and sets X and Y */
  Player(QPixmap *pm, int nx, int ny);
  /** A special function that is called upon to see direction of movement. This is necessary (rather than a case statement) in order to allow diagonal movement. */
  void change(bool left, bool right, bool up, bool down);
  /** Defines the movement of the Player */
  void move();
  /** Sets X */
  void setX(int nx);
  /** Gets X 
  @return X value*/
  int getX();
  /** Gets Y 
  @return Y Value*/
  int getY();
  /** Sets Y */
  void setY(int ny);
  
  
private:
  int x;
  int y;
  int vX;
  int vY;
  QPixmap *pixMap;
  QGraphicsPixmapItem *graphicsPixMap;
};



#endif
