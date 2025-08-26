/* FILE: gameplay.c
AUTHOR: Michael Durkan
PURPOSE: Gameplay functions for terminal based snake game.
LAST MOD: Apr 21 2024 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameplay.h"
#include "macros.h"
#include "random.h"
#include "terminal.h"

/*
NAME: userInput
PURPOSE: Accept a user input and move the character accordingly.
IMPORTS: gameBoard, playerPos - 2d array of chars for the game board before user
         input, and player position array.
EXPORTS: none.
*/
void userInput( char** gameBoard, int* playerPos )
{
    char dirInput;
    int invalidKey = TRUE;

    /* Loop for input if leading into border, or the wrong key input */
    while ( invalidKey )
    {   
        /* Accept user input without requiring the enter key */
        disableBuffer();
        scanf( " %c", &dirInput );
        enableBuffer();

        if ( dirInput == 'w' )
        {
            /* Only move player if not moving to a '*' element*/
            if ( gameBoard[playerPos[0] - 1][playerPos[1]] != '*' )
            {
                playerPos[0] -= 1;
                invalidKey = FALSE;
            }
        }
        else if ( dirInput == 'a' )
        {
            /* Only move player if not moving to a '*' element*/
            if ( gameBoard[playerPos[0]][playerPos[1] - 1] != '*' )
            {
                playerPos[1] -= 1;
                invalidKey = FALSE;
            }
        }
        else if ( dirInput == 's' )
        {
            /* Only move player if not moving to a '*' element*/
            if ( gameBoard[playerPos[0] + 1][playerPos[1]] != '*' )
            {
                playerPos[0] += 1;
                invalidKey = FALSE;
            }
        }
        else if ( dirInput == 'd' )
        {
            /* Only move player if not moving to a '*' element*/
            if ( gameBoard[playerPos[0]][playerPos[1] + 1] != '*' )
            {
                playerPos[1] += 1;
                invalidKey = FALSE;
            }
        }
        else
        {
            /* Print invalid input in location that will be overwritten in next
               board print */
            system( "tput cup 0 0" );
            printf( "Invalid key\n" );
        }
    }
}

/*
NAME: moveSnake
PURPOSE: Randomly move the snake into aligning element space.
IMPORTS: numRow, numCol, snakePos - number of row and columns for board, and 
         snake position array.
EXPORTS: none.
*/
void moveSnake( int numRow, int numCol, int* snakePos )
{
    int rowMov, colMov;
    int tmpSnakePos[2];

    do
    {
        /* Set amounts to move rows and columns to zero */
        rowMov = 0;
        colMov = 0;

        /* Set temporary snake position array to snake position */
        tmpSnakePos[0] = snakePos[0];
        tmpSnakePos[1] = snakePos[1];

        /* Loop if random values equate to zero movement in any direction */
        while ( ( rowMov == 0 ) && ( colMov == 0 ) )
        {
            /* Get a random x and y movement for snake from -1 to 1 */
            rowMov = randomUCP( -1, 1 );
            colMov = randomUCP( -1, 1 );
        }

        /* Apply random movements to temp snake position array */
        tmpSnakePos[0] += rowMov;
        tmpSnakePos[1] += colMov;

    /* Loop while random value directs snake onto border tile */
    }while ( ( tmpSnakePos[0] == 0 ) || ( tmpSnakePos[0] == numRow-1 ) ||
             ( tmpSnakePos[1] == 0 ) || ( tmpSnakePos[1] == numCol-1 ) );

    /* Update actual snake position array if a correct move */
    snakePos[0] = tmpSnakePos[0];
    snakePos[1] = tmpSnakePos[1];
}

/*
NAME: checkWin
PURPOSE: Check if player position equals food position and return outWin true 
         if so.
IMPORTS: playerPos, foodPos - position vectors for player and food position.
EXPORTS: outWin - boolean int for determining win or not.
*/

int checkWin( int* playerPos, int* foodPos )
{
    int outWin = FALSE;

    if ( ( playerPos[0] == foodPos[0] ) && ( playerPos[1] == foodPos[1] ) )
    {
        outWin = TRUE;
    }
     return outWin;
}

/*
NAME: checkLoss
PURPOSE: Check the player distance from the snake to determine if a loss.
IMPORTS: playerPos, snakePos, gameBoard - the position arrays of the player
         and snake, and the 2d array game board.
EXPORTS: outLose - TRUE or FALSE int for if loss.
*/
int checkLoss( int* playerPos, int* snakePos, char** gameBoard )
{
    int outLose = FALSE;

    /* If distance between player and snake on x and y is < 1 update gameBoard
       and return true for outLose */
    if ( ( abs( playerPos[0] - snakePos[0] ) <= 1 ) && 
         ( abs ( playerPos[1] - snakePos[1] ) <= 1 ) )
    {
        gameBoard[playerPos[0]][playerPos[1]] = '~';
        gameBoard[snakePos[0]][snakePos[1]] = ' ';
        
        outLose = TRUE;
    }

    return outLose;
}

/*
NAME: printResult
PURPOSE: Print win or lose message to terminal
IMPORTS: win - integer boolean for whether player has won or not
EXPORTS: none.
*/
void printResult( int win )
{
    if ( win ) 
    {
        printf( "You win!\n" );
    }
    else
    {
        printf( "You lose!\n" ); 
    }
}
