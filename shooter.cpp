#include <QtGui/QApplication>
#include "MainWindow.h"

/** @mainpage CSCI 102 PA #5
@section purpose Purpose/Overview
The Purpose of this PA is to create a fun and enjoyable game.
It will teach us how to use Qt as well as combining all of the knowledge that we have learned thus far.
@section requirements Requirements
The requirements include:
1. five "things" that move in different manners
2. A way to start, stop, and pause the game
3. Lives/Health
4. A way to keep track of score along with a name.
5. Speed up the game to increase the difficulty
*/
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  
  w.show();
  
  return a.exec();
}
