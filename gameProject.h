/*
Alex Maynard - S00298034
CSCI 3000 - Game Project
5/2/2018
*/

#include <iostream>
#include <ctime>
#include <string>
#include <unistd.h>
#include <termios.h>
#include <vector>
#include <tgmath.h>

using namespace std;

// Characters used in the game board.
const char EMPTY_SPACE = ' ';
const char SPACESHIP = '^';
const char ENEMY_CHAR = 'Y';
const char BLASTER_BOLT = '*';

// Basic controls
const char LEFT_MOVEMENT = 'a';
const char RIGHT_MOVEMENT = 'd';
const char FIRE_BLASTER = 'w';

// Map of the game.
char gameBoard [21][21] =
{
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    ",
   "                    "
};

//----------------------------------------------------------------------------------------------

// Main menu function
int mainMenu();

// Game function
void game(int numOfEnemies);

// Validates the position of the player and the enemies.
bool isAValidPosition(int x, int y);

/* 
This function was found on StackOverflow and needed because 
GetAsyncKeyState() and getch() are functions specific to Windows.
I need this function so that the game can continue running
without waiting for user input.
*/
char getch();

// Places the enemies on the game board.
//void enemyPlacement(int numberOfEnemies, Enemy enemies[]);

//----------------------------------------------------------------------------------------------

// Player's class
class Spaceship
{
   private:
      int x;
      int y;
      bool isShooting;
      int score;
      char c;

   public:
      Spaceship(int xIn, int yIn)
      {
         x = xIn;
         y = yIn;
         isShooting = false;
         score = 0;
      }

      // Moves the player's spaceship.
      void move()
      {
         //c = getch();
         if(c == LEFT_MOVEMENT && isAValidPosition(x-1, y))
            x--;
            
         if(c == RIGHT_MOVEMENT && isAValidPosition(x+1, y))
	    x++;
      }

      // Outputs the blaster bolt.
      void shoot()
      {
         if(c == FIRE_BLASTER)
            isShooting = true;
         else
            isShooting = false;
      }

      // Getter functions.
      int getX()
      {
         return x;
      }

      int getY()
      {
         return y;
      }

      int getIsShooting()
      {
         return isShooting;
      }

      int getScore()
      {
         return score;
      }
      void incrementScore()
      {
         score++;
      }
      void setC(char cIn)
      {
         c = cIn;
      }
};

// Blaster class
class Blaster
{
   private:
      int x;
      int y;
      bool active;

   public:
      Blaster() {}

      Blaster(int xIn, int yIn)
      {
         x = xIn;
         y = yIn;
         active = true;
      }

      int getX()
      {
         return x;
      }

      int getY()
      {
         return y;
      }

      bool getActive()
      {
         return active;
      }

      void setActive(bool activeIn)
      {
         active = activeIn;
      }

      void move()
      {
         if(isAValidPosition(x, y - 1))
         {
            y--;
         }         
      }
};

// Enemy class
class Enemy
{
   private:
      int x;
      int y;
      bool alive;

   public:
      Enemy()
      {
         y = 0;
         x = 0;
         alive = true;
      }
      Enemy(int startX)
      {
         x = startX;
         y = 0;
         alive = true;
      }

      // Allows the enemy to move down.
      void move()
      {
         if(isAValidPosition(x, y))
         {
            y++;
         }
      }

      // Getter and setter functions.
      int getX()
      {
         return x;
      }

      void setX(int xIn)
      {
         x = xIn;
      }

      int getY()
      {
         return y;
      }

      void setY(int yIn)
      {
         y = yIn;
      }

      bool getAlive()
      {
         return alive;
      }

      void setAlive(bool aliveIn)
      {
         alive = aliveIn;
      }
};
