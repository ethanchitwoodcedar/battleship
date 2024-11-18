// Author:
// Date:
// Purpose:

#include "battleship.h"

int main() {

   // variable declarations (you'll need others, of course)
   // Note: a good idea is the declare them as you need them to limit scope
   bool done = false;
   string move;

   welcome();
   Board computerBoard;
   Board humanBoard;
   initializeBoard(computerBoard);
   initializeBoard(humanBoard);
   // Initialize the game boards

   // Play the game until one player has sunk the other's ships
   while (!done) {

      // Clear the screen to prepare show the game situation before the moves
      // Display the game board situation

      // Get and validate the human player's move
      // BTW, in the following while loop (and the if statements also), I have
      // put a "0" in with the comments.  This is because in order for the
      // code to compile, you need to have something in between the parentheses

      while (0/* need to make sure that the human player's move is valid*/) {
			;
      }

      // Get and validate the computer's move
      while (0/* need to make sure that the computer's move is valid*/) {
			;
      }

      // Execute both moves
      // Clear the screen to show the new game situation after the moves
      // Display the new game board situation
      // Display the move choices each player made
      // Show the results of the moves
      // Take note if there are any sunken ships

      // determine if we have a winner
      if (0/* has either player sunk five ships? */) {
         // if one of the player's has sunk five ships the game is over
         done = true;
      } 
      else {
         // pause to let the user assess the situation
         pauseForEnter();
      }
   }

   // Announce the winner
   if (0/* the human was the winner */) {
      /* You won!!! */;
   }
   else if (0/* the computer was the winner */) {
      /* The computer won :( */;
   }
   else {
      /* The game was a tie */;
   }

   // pause to let the result of the game sink in

   return 0;
}
