#include <stdlib.h>
#include <stdio.h>

typedef struct mazeData {
    int x;
    int y;
    char data;
}Maze;


void createMaze(int x, int y) {
    Maze* map = (Maze*)malloc(sizeof(Maze*) * x * y);

}

// return legal input. if input is illegal, return ''
char getInput(){
    char input;
    input = scanf("%c",&input);
    toupper(input);
    char a[] = ['W','A','S','D','M','X'];
    for(int i = 0; i<6;i++)
    {
        if (input == a[i])
        {
            return input;
        }
    }
    printf("Wrong input");
    return ''
}


void loadMap(char[] fileName){
    FILE* f;
    f = fopen(fileName, "r");
    if (f == NULL)
    {
        printf("Error: cannot find file");
        exit(-1);
    }

}

//show the map
void showMap(){

}

//close the map
void closeMap(){

}

// the input can be 'W', 'A', 'S', 'D' and '', if input is '', then do not move
// this function will also check whether can move to the derection
void move(char input){
    

    if (checkWrongWay())
    {
        printf("cannot pass");
    }
    else
    {

    }
}
// if the road cannot pass,return 0,else return 1
int checkWrongWay(){

}





// if reach 'E', set win = 1 and print win
void checkWin(){

}