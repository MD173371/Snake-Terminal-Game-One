FILE: README.txt
AUTHOR: Michael Durkan
LAST MOD: 21 April 2024


Overal design: Created a simple game for the linux terminal, where a player
               tries to eat food before the snake bites them. Uses a 2d array
               of characters to present the game board and position variables to 
               keep track of where the player, snake and food are. Arrays are 
               memory allocated in the heap to allow for an input game board size
               from user. Random.c terminal.c and newsleep.c functions where
               provided by the course for use.
 
               Program should be run as such: ./eat <number of rows> <number of columns>

               Decided to utilize the system("tput cup 0 )" command to make the
               gameplay not flicker.

               No known bugs.

               
