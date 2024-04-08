#include "maze.h"

int win = 0;
char in = ''; // current input

int x;
int y;   // the location of player

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("argument error");
        return 0;
    }

    createMaze(argc[2], argc[3]);

    loadMap(argc[1]); // load map and get the location of 'S'

    while (!win)
    {
        in = getInput(); // get legal input
        if (in == 'M')
            showMap();
        elif (in == 'X')
        {
            closeMap();
            show();
        }
        elif (in == '')
            show();
        else
        {
            move(in); // if can pass,then move
            show();
            checkWin(); // check whether win the game
        }
        in = ''; // reset the input
    }
    freeMaze(argc[2], argc[3]);
    return 0;
}