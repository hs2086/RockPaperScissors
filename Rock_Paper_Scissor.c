#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

s32 Game_With_Computer(s8 You, s8 Com);

s32 main(){
    s8 you, com;
    system("cls");
    printf("\t\t\t\tRock Paper Scissor\n");
    printf("To Play With Computer Press 1 If You Want To Play With Your Friend Press 2\n");
    printf("1: Computer\n2: Friend\n");
    printf("Enter Your Choice: ");
    scanf(" %c", &you);
    system("cls");
    if (you == '1')
    {
        while(1){
            printf("\t\t\t\tRock Paper Scissor\n\n");
            printf("S: Stone\nP: Paper\nZ: Scissor\n\nQ: End Game\n\n\n");
            printf("Enter Your Choice: ");
            scanf(" %c", &you);
            if (you == 'q' || you == 'Q'){
                break;
            }
            if(you >= 'A' && you <= 'Z')
                you += 32;
            srand(time(NULL));
            com = rand() % 100 + 1;
            if(com <= 33){
                com = 's';
            }else if(com > 33 && com < 66){
                com = 'p';
            }else if(com >= 66){
                com = 'z';
            }
            if(you != 's' && you != 'p' && you != 'z'){
                printf("\n\n\n\t\t\t\tInvalid Choice\n");
                system("pause");
                system("cls");
                continue;
            }
            printf("Choice Of Comuter Is %c \n", com - 32);
            if(Game_With_Computer(you, com) == 1){
                printf("\n\n\n\t\t\t\tYou Are Win\n"); // Game Draw!
            }
            else if (Game_With_Computer(you, com) == -1){
                printf("\n\n\n\t\t\t\tGame Draw!\n"); // Game Draw!
            }else{
                printf("\n\n\n\t\t\t\tYou Are Lose!\n"); // Game Draw!
            }
            system("pause");
            system("cls");
        }
    }
    else if(you == '2')
    {
        while (1)
        {
            printf("\t\t\t\tRock Paper Scissor\n\n");
            printf("S: Stone\nP: Paper\nZ: Scissor\n\nQ: End Game\n\n\n");
            printf("Enter Choice Of Player 1: ");
            scanf(" %c", &you);
            printf("Enter Choice Of Player 2: ");
            scanf(" %c", &com);
            if (you == 'q' || you == 'Q')
                break;
            if (you >= 'A' && you <= 'Z')
                you += 32;
            if (com >= 'A' && com <= 'Z')
                com += 32;
            if (you != 's' && you != 'p' && you != 'z')
            {
                printf("\n\n\n\t\t\t\tInvalid Choice For Player 1\n");
                system("pause");
                system("cls");
                continue;
            }
            if (com != 's' && com != 'p' && com != 'z')
            {
                printf("\n\n\n\t\t\t\tInvalid Choice For Player 2\n");
                system("pause");
                system("cls");
                continue;
            }
            if (Game_With_Computer(you, com) == 1)
            {
                printf("\n\n\n\t\t\t\tPlayer 1 Is Win\n"); // Game Draw!
            }
            else if (Game_With_Computer(you, com) == -1)
            {
                printf("\n\n\n\t\t\t\tGame Draw!\n"); // Game Draw!
            }
            else
            {
                printf("\n\n\n\t\t\t\tPlayer 2 Is Win!\n"); // Game Draw!
            }
            system("pause");
            system("cls");
        }
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\t\t\t\tInvalid Choise\n");
    }
    return 0;
}

s32 Game_With_Computer(s8 You, s8 Com){
    s32 res;
    if(You == Com)
        res = -1;
    else if(You == 's' && Com == 'p'){
        res = 0;
    }
    else if (You == 's' && Com == 'z'){
        res = 1;
    }
    else if (You == 'p' && Com == 's'){
        res = 1;
    }
    else if (You == 'p' && Com == 'z'){
        res = 0;
    }
    else if (You == 'z' && Com == 'p'){
        res = 1;
    }
    else if (You == 'z' && Com == 's'){
        res = 0;
    }
    return res;
}
