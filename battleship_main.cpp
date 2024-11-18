// Author: Ethan Chitwood
// Date: 11/12/24
// Purpose: CS1210

#include "battleship.h"

int main() {

   bool done = false;
   bool moveInvalid = true;
   string move;
   string humMove;
   int resultHum;
   int resultCom;
   int moveCheck;
   int row;
   int col;
   int comTally = 0;
   int humTally = 0;

   welcome();
   Board computerBoard;
   Board humanBoard;
   initializeBoard(computerBoard);
   initializeBoard(humanBoard);
   pauseForEnter();
   clearTheScreen();

   // Play the game until one player has sunk the other's ships
   while (!done) {

      clearTheScreen();
      displayBoard(1, 1, HUMAN, humanBoard);
      displayBoard(1, 35, COMPUTER, computerBoard);

      while (moveInvalid) {
	 move = getResponse(15, 1,"Please enter your move: ");
	 moveCheck = checkMove(move, computerBoard, row, col);
	 if (moveCheck == VALID_MOVE) {
	    moveInvalid = false;

	 } 
	 else if (moveCheck == ILLEGAL_FORMAT) {
            clearTheLine(14);
	    writeMessage(14, 1, "Invalid Move. Illegal format.");
	 }
	 else if (moveCheck == REUSED_MOVE) {
            clearTheLine(14);
	    writeMessage(14, 1, "Invalid Move. Move already taken.");
	 }
      }

      resultHum = playMove(row, col, computerBoard);
      moveInvalid = true;
      humMove = move;

      // Get and validate the computer's move
      while (moveInvalid) {
         move = randomMove();
         moveCheck = checkMove(move, humanBoard, row, col);
         if (moveCheck == VALID_MOVE) {
            moveInvalid = false;
         }
      }

      resultCom = playMove(row, col, humanBoard);
      moveInvalid = true;
      
      clearTheScreen();
      displayBoard(1, 1, HUMAN, humanBoard);
      displayBoard(1, 35, COMPUTER, computerBoard);

      if (resultHum != 0) {
         humTally++;
      }
      if (resultCom != 0) {
         comTally++;
      }
      
      writeMessage(15, 1, "You chose: " + humMove);
      writeMessage(16, 1, "The computer chose: " + move);
      writeResult(18, 1, resultHum, HUMAN); 
      writeResult(19, 1, resultCom, COMPUTER);

      // determine if we have a winner
      if (humTally == 17 || comTally == 17) {
         done = true;
      } 
      else {
         pauseForEnter();
      }
   }

   // Announce the winner
   if (humTally > comTally) {
      writeMessage(21, 1, "You Won!");
   }
   else if (comTally > humTally) {
      writeMessage(21, 1, "Computer Won!");
      
   }
   else {
      writeMessage(21, 1, "The game was a tie!");
   }

   pauseForEnter();
   clearTheScreen();

   return 0;
}
