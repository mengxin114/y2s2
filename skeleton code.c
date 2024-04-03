#include<stdio.h>
#include"maze.h"




typedef struct mazeData
{

}data;





int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("argc error");
        return EXIT_FAILURE;
    }
    readFile(argc[0]);

}