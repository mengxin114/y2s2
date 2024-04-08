#include <stdlib.h>
#include <stdio.h>

char **map;//store the data


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
    // return legal input. if input is illegal, return ''
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