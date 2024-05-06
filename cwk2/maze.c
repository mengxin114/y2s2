#include "maze.h"

#define LINE_MAX 1024

int main(int argc, char *argv[])
{
    load();
    while (!win)
    {
        in = getInput(); // get legal input
        if (in == 'M')
        {
            showMap();
        }
        else if (in == '\0')
        {
            printf("wrong input");
        }
        else if (in == 'Q')
        {
            exit(0);
        }
        else
        {
            move(in);   // if can pass,then move
            checkWin(); // check whether win the game
        }
        in = '\0'; // reset the input
    }
}

void checkData(char *buf, int *count)
{
    if (strlen(buf) != width)
    {
        exit(3);
    }
    if (width < 5 || width > 100)
    {
        exit(3);
    }
    for (int i = 0; i < width; i++)
    {
        if (buf[i] == 'S' || buf[i] == 'E')
        {
            count += 1;
        }
    }
    if (count > 2)
    {
        exit(3);
    }
}
void createMaze(int height, int width)
{
    // create the data structure
    map = (char **)malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++)
        map[i] = (char *)malloc(sizeof(char) * width);
}
void load(char fileName[])
{
    height = 1;
    width = 0;
    int count = 0;
    char buf[];
    char s[];
    FILE *f;
    f = fopen(fileName, "r");
    if (f == NULL)
    {
        printf("Error: cannot find file");
        exit(-1);
    }
    // get height and width
    fgets(s, LINE_MAX, f);

    width = strlen(s);
    while (fgets(buf, LINE_MAX, f))
    {
        height++;
        checkData();
    }
    rewind(f);
    createMaze(height, width);
    int i = 0;
    while (fgets(buf, LINE_MAX, f))
    {
        map[i] = buf;
        i++;
    }
}
int checkWrongWay(int dx, int dy)
{
    if (x + dx < 0 || x + dx > width)
    {
        return 0;
    }
    if (y + dy < 0 || y + dy > height)
    {
        return 0;
    }
    if (map[y + dy][x + dx] == '#')
    {
        return 0;
    }
    return 1;
}

void move(char input)
{
    // the input can be 'W', 'A', 'S', 'D' and '', if input is '', then do not move
    // this function will also check whether can move to the derection
    for (int i = 0; i < 4; i++)
    {
        if (direction[i].tag == input)
        {
            if (checkWrongWay(direction[i].x, direction[i].y))
            {
                printf("cannot pass");
            }
            else
            {
                x = x + direction[i].x;
                y = y + direction[i].y;
            }
        }
    }
}

char getInput()
{
    // return legal input. if input is illegal, print "Wrong input" and return ''
    // change all the input into uppercase
    char input;
    input = scanf("%c", &input);
    toupper(input);
    char a[] = [ 'W', 'A', 'S', 'D', 'Q' ];
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        if (input == a[i])
        {
            return input;
        }
    }
    return '\0';
}

void checkWin()
{
    if (map[y][x] == 'E')
    {
        win = 1;
    }
    else
    {
        win = 0;
    }
}

void showMap()
{
    for (int j = 0; i < height; i++)
    {
        for (int i = 0; j < width; j++)
        {
            if (j == y && i == x)
                printf('X');
            else
                printf("%c", map[j][i]);
        }
        printf("\n");
    }
}