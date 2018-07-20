#include "header.h"

COORD coord = {0, 0};
void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void t()
{
    time_t t;
    time(&t);
   printf("%s",ctime(&t));
}


int main()
{
    system("title Vote Machine (Class Project)");
    timer=0;checker=0;
    mainmenu();
    return 0;
}

int mainmenu()
{
    disp();
    printf("\tPlease select which kind of user you are : \n\n\t\t 1. User ( Password Required )\n\n\t\t 2. Voter\n\n\t\t 3. Exit\n\n\t--------------------------------------\n\n\t\tEnter your choice : ");
    switch(getch())
    {
    case '1':
        password();
        break;
    case '2':
        vmenu();
        break;
    case '3':
        disp();
        printf("\n\n\t\t\tThanks You ");
        int j;
        for(j=0;j<5;j++)
        {
            printf(". ");
            Sleep(500);
        }
        return 0;
    default:
        printf("\n\n\t\t You have entered wrong choice . Please wait ");
        int i;
        for(i=0;i<5;i++)
        {
            printf(". ");
            Sleep(500);
        }
        mainmenu();
    }
    return 0;
}

void disp()
{
    system("cls");
    system("color 0f");
    printf("\t\t\t#########  New Tech. Voting MAchine  ###########\n\t\t\t\t   ");
    t();
    printf("\n----------------------------------------------------------------------------------------------------------\n\n");
}

void disp_ad()
{
    system("cls");
    system("color 06");
    printf("\t\t\t#########  New Tech. Voting MAchine  ###########\n\t\t\t\t   ");
    t();
    printf("\t\t\t\t   |== Admin Panel ==|\n");
    printf("\n----------------------------------------------------------------------------------------------------------\n\n");

}

void disp_v()
{
    system("cls");
    system("color 0e");
    printf("\t\t\t#########  New Tech. Voting MAchine  ###########\n\t\t\t\t   ");
    t();
    printf("\n\t\t\t\t   |== Voters Section ==|\n");
    printf("\n----------------------------------------------------------------------------------------------------------\n\n");

}


