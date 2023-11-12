#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
void user(int * ptr)
{
    int id=0;
    char option;
    system("clear");
    printf("Welcome to user section\n----------------------\n");
    printf("Select one option:\n\n1-Search for Id\n\n2-Back to main menu\n");
    //get one option and preventing enter key from being a one because of bouncing
    while(1)
    {
        if(option!='1'&&option!='2')
        {

        }
        else
        {
             printf("Select one option:\n\n1-Search for Id\n\n2-Back to main menu\n");
        }

        scanf("%c",&option);
        //option 1 for user to know about his info and reservation time
        if(option=='1')
        {
            system("clear");
            printf("Enter Id:\n");
            scanf("%d",&id);
            system("clear");
            Search(id);
            printList();
        }
        else if (option=='2')
        {
            *ptr=0;
             break;
        }
        else if(option!='\n')
        {
            option='1'; 
            system("clear");
            if(id==0 || id=='0')
            {

            }
            else
            {
                printf("Wrong Option\n-----------\n");
            }

        }


    }


}
