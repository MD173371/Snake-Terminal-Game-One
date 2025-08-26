/*FILE: memory.h
AUTHOR: Michael Durkan
PURPOSE: Provide function prototypes for the functions within memory.c
LAST MOD: 21 April 2024  */

#ifndef MEMORY_H
#define MEMORY_H

char** initBoardMem( int numRow , int numCol );
void freeBoardMem( int numRow, char*** gameBoard );

#endif
