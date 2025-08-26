/* FILE: gameplay.h
AUTHOR: Michael Durkan
PURPOSE: Provide function prototypes for functions within gameplay.c
LAST MOD: April 21 2024  */

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

void userInput( char** gameBoard, int* playerPos );                               
void moveSnake( int numRow, int numCol, int* snakePos );                          
int checkLoss( int* playerPos, int* snakePos, char** gameBoard );                 
int checkWin( int* playerPos, int* foodPos ); 
void printResult( int win );

#endif
