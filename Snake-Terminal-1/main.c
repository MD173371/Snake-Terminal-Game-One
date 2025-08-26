/* FILE: main.c
AUTHOR: Michael Durkan
PURPOSE: Terminal based snake game application main file.
LAST MOD: Apr 21 2024 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"
#include "gameboard.h"
#include "gameplay.h"
#include "random.h"
#include "terminal.h"
#include "newsleep.h"
#include "macros.h"

int main( int argc, char** argv )
{ 
    int numRow, numCol, numArgs, win = FALSE, lose = FALSE;
    
    /* Position array follows format: "***"Pos[<Row Number>][<Column Number>] 
       (starting at row/colum number 0) */
    int foodPos[2], snakePos[2], playerPos[2];

    char** gameBoard;

    /* Initialise random number generator function */
    initRandom();

    /* Calculate number of command arguments */
    numArgs = argc - 1;

    /* Print error message if incorrect number of command arguments input */
    if ( numArgs == 2 )
    {

        /* Initalise board dimension variables*/
        initDim( &numRow, &numCol, argv );

        /* Print error message if either input argument is < 5 */
        if ( ( numRow >= 7 ) && ( numCol >= 7 ) )
        {
            /* Set the starting position coordinate arrays for the player,
               snake and food */
            setPlayers( numRow, numCol, playerPos, snakePos );
            setFood( numRow, numCol, foodPos );

            /* Allocate memory for gameboard, place the characters and print
               on fresh terminal */
            gameBoard = initBoardMem( numRow, numCol );
            gameBoard = fillGameBoard( numRow, numCol, gameBoard, playerPos,
                        snakePos, foodPos );
            system( "clear" );
            printGameBoard( numRow, numCol, gameBoard );

            while ( !( win || lose ) )
            {
                /* Get movement input from user and update player Position */
                userInput( gameBoard, playerPos );
                gameBoard = fillGameBoard( numRow, numCol, gameBoard, playerPos,
                            snakePos, foodPos );

                /* Check distance from snake to determine if player has lost */
                lose = checkLoss( playerPos, snakePos, gameBoard );

                if ( !lose )
                {
                    /* Move snake to random aligning position and update board */
                    moveSnake( numRow, numCol, snakePos );
                    gameBoard = fillGameBoard( numRow, numCol, gameBoard,
                                playerPos, snakePos, foodPos );

                    /* Check players distance to food to see if a win */
                    win = checkWin( playerPos, foodPos );
                }

                /* Clear terminal and print game board */
                printGameBoard( numRow, numCol, gameBoard );
            }

            /* Free memory allocated by malloc for 2d array */
            freeBoardMem( numRow, &gameBoard );

            /* Print to terminal if player won or lost */
            printResult(win);
        }
        else
        {
            printf( "Error: Incorrect col/row length, must be greater than 4\n" );
        }
    }
    else
    {
        printf( "Error: Incorrect number of arguments\n" );
        printf( "Usage: ./eat <map_row> <map_col>\n" );
    }

    return 0;
}
