/*
Alex Maynard - S00298034
CSCI 3000 - Game Project
5/2/2018
*/

#include "gameProject.h"

int main()
{
   int numOfEnemies = mainMenu();
   game(numOfEnemies);
   cin.ignore();
   cin.get();
   return 0;
}

int mainMenu()
{
   int mainMenuChoice;
   int numberOfEnemies;

   // The program will continue to output the menu until the user selects a valid input.
   do
   {
      cout << "\nWelcome to my first game!\n";
      cout << "Please select what you would like to do.\n";
      cout << "\n1. Start the game.\n";
      cout << "2. Exit the game.\n";
      cin >> mainMenuChoice;

      switch(mainMenuChoice)
      {
         case 1:
            cout << "\nHow many enemies would you like to fight? (1-20)\n";
            cout << "1-9 is recommended. Go above at your own risk.\n";
            cin >> numberOfEnemies;
            system("clear");
            return numberOfEnemies;
         case 2:
            cout << "\nThanks for playing! Come back next time!\n";
            exit(1);
         default:
            cout << "\nYou entered " << mainMenuChoice << " which is not a valid option.\n";
            cout << "Please try again.\n";
      }
   } while(mainMenuChoice != 1 || mainMenuChoice != 2);
}

// Places enemy ships according to how many enemies the user wants to fight.
void enemyPlacement(int numberOfEnemies, Enemy enemies[])
{
   if(numberOfEnemies == 20)
   {
      for(int n = 0; n < numberOfEnemies; n++)
      {
         enemies[n].setX(n);
      }
   }
 
   else
   {
      for(int n = 0; n < numberOfEnemies; n++)
      {
         int x = n;
         enemies[n].setX(x);
      }
   }
}

// This is the function where the game takes place.
void game(int numOfEnemies)
{
   Spaceship player(0, 19);
   Enemy enemyList[numOfEnemies];
   vector <Blaster> blasterBolts;
   enemyPlacement(numOfEnemies, enemyList);
   bool gameOver = false;

   // The program will explain the controls.
   cout << "w to shoot, a flies left, d flies right.\nPress enter to play!\n";

   while(!gameOver)
   {
      player.setC(getch());
      // Move function
      player.move();

      // Shoot function
      player.shoot();

      // Adds a blaster bolt to the blaster vector
      if(player.getIsShooting())
      {
         blasterBolts.push_back(Blaster(player.getX(), player.getY()));
      }

      // Blaster move function
      for(int b = 0; b < blasterBolts.size(); b++)
      {
         if(blasterBolts[b].getActive())
            blasterBolts[b].move();
      }

      // Enemy move function
      for(int e = 0; e < numOfEnemies; e++)
      {
         int enemyX = enemyList[e].getX();
         int enemyY = enemyList[e].getY();

         //below for loop tests for dead enemy
         for(int b = 0; b < blasterBolts.size(); b++)
         {
            int boltX = blasterBolts[b].getX();
            int boltY = blasterBolts[b].getY();
            if(enemyX == boltX  && (enemyY == boltY - 1 || enemyY == boltY) && enemyList[e].getAlive())
            {
               enemyList[e].setAlive(false);
               blasterBolts[b].setActive(false);
               player.incrementScore();
            }
         }
         if(enemyList[e].getAlive())
            enemyList[e].move();
      }    

      // Prints the game board
      system("clear");
      for(int y = 0; y < 20; y++)
      {
         for(int x = 0; x < 20; x++)
         {
	    if(player.getX() == x && player.getY() == y)
	       cout << SPACESHIP;
	    else
            {
               bool enemyHere = false;
               for(int e = 0; e < numOfEnemies; e++)
               {
                  int enemyX = enemyList[e].getX();
                  int enemyY = enemyList[e].getY();
                  //check for loss
                  if(enemyY == 19)
                     gameOver = true;
                  if(enemyList[e].getX() == x && enemyList[e].getY() == y && enemyList[e].getAlive())
                  {
                     cout << ENEMY_CHAR;
                     enemyHere = true;
                  }  
               }
               if(!enemyHere)
               {
                  bool blasterBoltHere = false;
                  for(int b = 0; b < blasterBolts.size(); b++)
                  {
                     int boltX = blasterBolts[b].getX();
                     int boltY = blasterBolts[b].getY();
                     if(blasterBolts[b].getX() == x && blasterBolts[b].getY() == y && blasterBolts[b].getActive())
                     {
                        cout << BLASTER_BOLT;
                        blasterBoltHere = true;
                     }  
                  }
                  if(!blasterBoltHere)
	             cout << gameBoard[x][y];
               }
            }
         }
         cout << endl;
      }

      
      //win condition
      if(numOfEnemies == player.getScore())
      {      
         system("clear");
         cout << "\nYour final score is: " << player.getScore();
         cout << "\nCongratulations! You've won!\n";
         cout << "Now get outta here.\n";
         exit(2);
      }

      // loss
      if(gameOver)
      {
         system("clear");
         cout << "\nYour final score is: " << player.getScore();
         cout << "\nSorry, you lost.\n";
         cout << "Better luck next time, scrub.\n";
         exit(3);
      }
   }
}

// Checks whether the player and the enemies are in a valid position.
bool isAValidPosition(int x, int y)
{
   return(x >= 0 && x < 20 && y >=0 && y < 20);
}

char getch() 
{
   char buf = 0;
   struct termios old = {0};
   if (tcgetattr(0, &old) < 0)
      perror("tcsetattr()");
   old.c_lflag &= ~ICANON;
   old.c_lflag &= ~ECHO;
   old.c_cc[VMIN] = 1;
   old.c_cc[VTIME] = 0;
   if (tcsetattr(0, TCSANOW, &old) < 0)
      perror("tcsetattr ICANON");
   if (read(0, &buf, 1) < 0)
      perror ("read()");
   old.c_lflag |= ICANON;
   old.c_lflag |= ECHO;
   if (tcsetattr(0, TCSADRAIN, &old) < 0)
      perror ("tcsetattr ~ICANON");
   return (buf);
}
