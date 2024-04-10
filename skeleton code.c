#include "maze.h"


void createMaze(int height, int width) {
    // create the data structure
    map = (char**)malloc(sizeof(char*) * height);
    for (int i = 0; i < height; i++)
        map[i] = (char*)malloc(sizeof(char) * width);
}

void freeMaze(int height, int width){
    // free the pointer of map
    for (int i = 0; i <height; i++)
        free(map[i]);
    free(map);
}


char getInput(){
    // return legal input. if input is illegal, print "Wrong input" and return ''
    // change all the input into uppercase
    char input;
    input = scanf("%c",&input);
    toupper(input);
    char a[] = ['W','A','S','D','M','X'];
    for(int i = 0; i < 6;i++)
    {
        if (input == a[i])
            return input;
    }
    printf("Wrong input");
    return ''
}


void loadMap(char[] fileName){
    // open the file and load it into maze
    // get the location of S
    // if can not load correctly, exit(-1)
    // check whether the size is correct for the file
    // check illegal content of the file
    // check the 
    FILE* f;
    f = fopen(fileName, "r");
    if (f == NULL)
    {
        printf("Error: cannot find file");
        exit(-1);
    }
    if (checkContent())
}

void showMap(){
    //show the map
    //if can not show the map, exit(-1)
}

void closeMap(){
    //close the map
    //if can not close, exit(-1)
}



void show(){
    //print the maze
}


void move(char input){
    // the input can be 'W', 'A', 'S', 'D' and '', if input is '', then do not move
    // this function will also check whether can move to the derection

    if (checkWrongWay())
    {
        printf("cannot pass");
    }
    else
    {
        // apply move to player
    }
}



int checkWrongWay(){
    // cannot move through walls
    // cannot move off the edge
    // if the road cannot pass,return 0,else return 1
}



void checkWin(){
    // if reach 'E', set win = 1 and print win
}



char **map;//store the data

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