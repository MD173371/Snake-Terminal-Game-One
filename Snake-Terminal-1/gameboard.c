/* FILE: gameboard.c
AUTHOR: Michael Durkan
PURPOSE: Gameboard set and printing functions for terminal based snake game.
LAST MOD: Apr 21 2024 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "gameboard.h"
#include "random.h"
#include "newsleep.h"

/*
NAME: initDim
PURPOSE: Initialize dimensions, number of row and column variables from
         command arguments input, adding 2 to account for game border.
IMPORTS: numRow, numCol, argv - the number of rows, columns variables and dimensions
         input in arguments.
EXPORTS: none.
*/
void initDim( int* numRow, int* numCol, char** argv )
{
    /* Convert input arguments from string to integer, add 2, and correspondingly
       set to number of rows and columns */
    *numRow = atoi( argv[1] ) + 2;
    *numCol = atoi( argv[2] ) + 2;
}

/*
NAME: setFood
PURPOSE: randomly assign a positioning for the food character
IMPORTS: numRow, numCol, foodPos - Number of columns and rows, and position array
         of the food character.
EXPORTS: none.
*/
void setFood( int numRow, int numCol, int* foodPos )
{
    /* Position array follows format: foodPos[<Row Number>][<Column Number>] 
       (starting at row/colum number 0) */
    do
    {
        /* randomly assign x and y positions for food, based on size of
           playable area */
        foodPos[0] = randomUCP( 1, numRow - 2 );
        foodPos[1] = randomUCP( 1, numCol - 2 );

    /* Loop if food placed in the position of player or position of snake */
    } while ( ( ( foodPos[0] == numRow - 2 ) && ( foodPos[1] == numCol - 2 ) ) ||
              ( ( foodPos[0] == 1 ) && ( foodPos[1] == 1 ) ) );
}

/*
NAME: setPlayers
PURPOSE: Set initial position of player and snake.
IMPORTS: numRow, numCol, playerPos, snakePos - number of rows and columns for gameboard
         and the position coordinates arrays for the player and snake.
EXPORTS: none.
*/
void setPlayers( int numRow, int numCol, int* playerPos, int* snakePos )
{
    /* Position array follows format: playerPos[<Row Number>][<Column Number>]
       and playerPos[<Row Number>][<Column Number>] (starting at row/column
       number 0) */
    playerPos[0] = 1;
    playerPos[1] = 1;
    snakePos[0] = numRow - 2;
    snakePos[1] = numCol - 2;
}

/*
NAME: fillGameboard
PURPOSE: Update the gameboard array with the position arrays of the game characters
IMPORTS: numRow, numCol, gameboard, playerPos, snakePos - number of rows and columns 
         for gameboard, gameboard 2d array of char, and the position coordinates arrays 
         for the player and snake.
EXPORTS: gameboard - the 2d char array once updated with the positions.
*/
char** fillGameBoard( int numRow, int numCol, char** gameBoard, int* playerPos,
                     int* snakePos, int* foodPos )
{
    int i, j;

    /* Fill the board with white space characters */
    for ( i = 0; i < numRow; i++ )
    {
        for ( j = 0; j < numCol; j++ )
        {
            gameBoard[i][j] = ' ';
        }
    }
    /* Fill the top and bottom borders with '*' characters */
    for ( j = 0; j < numCol; j++ )
    {
        gameBoard[0][j] = '*';
        gameBoard[numRow - 1][j] = '*';
    }
    /* Fill the left and right borders with '*' characters */
    for ( i = 0; i < numRow; i++ )
    {
        gameBoard[i][0] = '*';
        gameBoard[i][numCol - 1] = '*';
    }
    /* Place the food character on the board */
    gameBoard[foodPos[0]][foodPos[1]] = '@';

    /* Place the player character on the board */
    gameBoard[playerPos[0]][playerPos[1]] = 'P';

    /* Place the snake character on the board */
    gameBoard[snakePos[0]][snakePos[1]] = '~';

    return gameBoard;
}

/*
NAME: printGameBoard
PURPOSE: Print the game board in the terminal.
IMPORTS: numRow, numcol, gameBoard - the number of rows and columns of the
         gameboard, and the gameboard array.
EXPORTS: none.
*/
void printGameBoard( int numRow, int numCol, char** gameBoard )
{
    int i, j;

    /* Set cursor at the start of the terminal so it overwrites previous board */
    system( "tput cup 0 0" );
    
    /* Print the 2d array for game board */
    for ( i = 0; i < numRow; i++ )
    {
        for ( j = 0; j < numCol; j++ )
        {
            printf( "%c", gameBoard[i][j] );
        }
        printf( "\n" );

    }

    /* Print the input movement controls */
    printf( "Press 'w' key to move up   \n" );
    printf( "Press 's' key to move down \n" );
    printf( "Press 'a' key to move left \n" );
    printf( "Press 'd' key to move right\n" );
    
    /* Smooth animation with a sleep command */
    newSleep( 0.003 );
}
