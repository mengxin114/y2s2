#ifndef __TASKOP_H__
#define __TASKOP_H__
#include <stdlib.h>
#include <stdio.h>



char **map;
int width;
int height;
int win = 0;
char in = '\0';
int x;
int y;
struct dir
{
    char tag;
    int x;
    int y;

};
struct dir direction[4] = {
    [0]{
        .tag = 'W',
        .x = 0,
        .y = -1
    },
    [1]{
        .tag = 'A',
        .x = -1,
        .y = 0
    },
    [2]{
        .tag = 'S',
        .x = 0,
        .y = 1
    },
    [3]{
        .tag = 'D',
        .x = 1,
        .y = 0
    },
};



//create maze
void creatMaze(int height, int width);


//clear the maze data
void freeMaze(int height, int width);

//get legal keyboard input
char getInput();

//load map into the maze
void load(char[] fileName);

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