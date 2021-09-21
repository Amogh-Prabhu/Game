#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<conio.h>

int gameover;
const length=90,height=25;
int y,bx,by;
const x1=5,x2=length-5;
int score;
int dir,bdir;
enum dir{STOP=0,UP,DOWN};
enum bdir{UR=3,DR,UL,DL};
char ball;

void intro()
{
    system("cls");
    char start='*',quit=' ';
    int s=0;
    while(!s)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO THE GAME\n\n\t\t\t\t\t\tSTART %c\n\t\t\t\t\t\tQUIT  %c\n\n\n\t\t\t\t\t\t**(Press L to select)**",start,quit);
        switch(getch())
        {
        case 'w':
            start='*';
            quit=' ';
            break;
        case 's':
            start=' ';
            quit='*';
            break;
        case 'l':
            {
                s++;
                if(start==' ')
                exit(0);
            }
        default:
            break;
        }
    }
}

void Setup()
{

    gameover=0;
    score=0;
    y=height/2;
    dir=STOP;
    bx=length/2,by=height/2;
    bdir=rand()%4+3;
    ball='O';

}

void base()
{
    system("cls");
    printf("\n\t(Press W to move UP and Press S to move DOWN)\n\n");
    for(int j=0;j<height;j++)
    {
        printf("\t");
        for(int i=0;i<length+2;i++)
        {
            if(j==0||j==height-1)
                printf("%c",219);
            else if(i==0||i==length-1)
                printf("%c%c",219,219);
            else
                if(i==x1&&j==y||i==x2&&j==y||i==x1&&j==y-1||i==x2&&j==y-1||i==x1&&j==y+1||i==x2&&j==y+1)
                    printf("%c",219);
            else
                if(i==bx&&j==by)
                    printf("%c",ball);
            else
                printf(" ");

        }
        printf("\n");
    }
    printf("\n\tSCORE: %d\n",score);
}

void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'w':
            dir=UP;
            break;
        case 's':
            dir=DOWN;
            break;
        case 'x':
            gameover=1;
        default:
            break;
        }
    }
}

void movement()
{
    //plate
    switch(dir)
    {
    case UP:
        y-=2;
        dir=STOP;
        break;
    case DOWN:
        y+=2;
        dir=STOP;
        break;
    default:
        break;
    }

    //ball
    switch(bdir)
    {
    case UR:
        by-=1;
        bx+=2;
        break;
    case UL:
        by-=1;
        bx-=2;
        break;
    case DR:
        by+=1;
        bx+=2;
        break;
    case DL:
        by+=1;
        bx-=2;
        break;
    default:
        break;

    }
}

void logic()
{
    //plate
    if(y>=height-3)
        y=height-3;
    else if(y<=2)
        y=2;

    //ball
    if(by==1)
    {
        ball='o';
        switch(bdir)
        {
        case UR:
            bdir=DR;
            break;
        case UL:
            bdir=DL;
            break;
        }
    }
    else if(by==height-2)
    {
        ball='o';
        switch(bdir)
        {
        case DR:
            bdir=UR;
            break;
        case DL:
            bdir=UL;
            break;
        }
    }
    else if((bx==6||bx==5)&&(by==y||by==y-1||by==y+1)||(bx==length-6||bx==length-5)&&(by==y||by==y-1||by==y+1))
    {
        score++;
        ball='o';
        if(bx==5)
            bx=6;
        if(bx==length-5)
            bx=length-6;
        switch(bdir)
        {
        case UR:
            bdir=UL;
            break;
        case UL:
            bdir=UR;
            break;
        case DR:
            bdir=DL;
            break;
        case DL:
            bdir=DR;
            break;
        }
    }
    else
        ball='O';
    if(bx<=0||bx>=length-1)
        gameover++;
}

int main()
{
    intro();
    Setup();
    base();
    printf("\tPress 'W' to move up and 'S' to move down!!");
    getch();
    while(!gameover)
    {
        base();
        input();
        movement();
        logic();
    }
    printf("\n\tPRESS ANY KEY!!");
    getch();
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t  GAME OVER!");
    getch();
    printf("\n\n\n\n\n");
    return 0;
}
