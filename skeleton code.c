#include "maze.h"

int win = 0;
char in = '\0'; // current input

int x;
int y;   // the location of player

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("argument error");
        return 0;
    }
    else
        printf("correct arguments");

    createMaze(atoi(argv[2]), atoi(argv[3]));

    loadMap(argv[1]); // load map and get the location of 'S'

    while (!win)
    {
        in = getInput(); // get legal input
        if (in == 'M')
        {
            showMap();
        }
        else if (in == 'X'){
            closeMap();
            show();
        }
        else if (in == '\0'){
            show();
        }
        else{
            move(in); // if can pass,then move
            show();
            checkWin(); // check whether win the game
        }
        in = '\0'; // reset the input
    }
    freeMaze(atoi(argv[2]), atoi(argv[3]));
    return 0;
}