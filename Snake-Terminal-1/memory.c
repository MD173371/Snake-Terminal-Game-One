/* FILE: memory.c
AUTHOR: Michael Durkan
PURPOSE: Memory allocate and free functions for Terminal based snake game.
LAST MOD: Apr 21 2024 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"

/*
NAME: initBoardMem
PURPOSE: initialise the 2d char array for the game board in memory.
IMPORTS: numRow, numCol - The number of rows and columns for the board.
EXPORTS: gameBoard - 2d game board array of char
*/
char** initBoardMem( int numRow, int numCol )
{
    int i;
    char** gameBoard;

    /* Allocate the memory for array of row pointers */
    gameBoard = ( char** ) malloc( sizeof( char* ) * numRow );

    /* Allocate the memory for each row of characters */
    for ( i = 0; i < numRow; i++ )
    {
        gameBoard[i] = ( char* ) malloc( sizeof( char ) * numCol );
    }

    return gameBoard;
}

/*
NAME: freeBoardMem
PURPOSE: Free the memory of the malloc'd arrays of the game board, and set
         pointers to NULL.
IMPORTS: numRow, numCol, gameBoard - The number of rows of the board and a
         pointer to the 2d char array of the board.
EXPORTS: none.
*/
void freeBoardMem( int numRow , char*** gameBoard )
{
    int i;

    /* Free the memory for each row of char, and set to NULL */
    for ( i = 0; i < numRow; i++ )
    {
        free( ( *gameBoard )[i] );
        ( *gameBoard )[i] = NULL;
    }

    /* Free the memory for the array of row pointers and set to NULL */
    free( *gameBoard );
    *gameBoard = NULL;
}
