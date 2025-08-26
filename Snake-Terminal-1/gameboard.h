/*FILE: gameboard.h
AUTHOR: Michael Durkan
PURPOSE: Provide function prototypes for functions within gameboard.c
LAST MOD: 21 April 2024  */

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

void initDim( int* numRow, int* numCol, char** argv );                            
void setFood( int numRow, int numCol, int* foodPos );                             
void setPlayers( int numRow, int numCol, int* playerPos, int* snakePos );         
char** fillGameBoard( int numRow, int numCol, char** gameBoard, int* playerPos,  
                     int* snakePos, int* foodPos );                              
void printGameBoard( int numRow, int numCol, char** gameBoard ); 

#endif
