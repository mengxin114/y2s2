#ifndef __TASKOP_H__
#define __TASKOP_H__
#include <stdlib.h>
#include <stdio.h>

//create maze
void creatMaze(int height, int width);


//clear the maze data
void freeMaze(int height, int width);

//get legal keyboard input
char getInput();

//load map into the maze
void loadMap(char[] fileName);

//show map
void showMap();

//close map
void closeMap();

//show the location
void show();

//move the location of player
void move(char input);

//check whether can go through
int checkWrongWay();

//check the condition of win
void checkWin();

#endif