#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
int main()
{
    //Reserve : creates Nodes of Slots
    Reserve();
    int counter=0,r=0,c2=0;
    char ResPassword[6];
    char Password[6];
    char option,key;
    int *ptr=&r;
    //Set A password to the system
    system("clear");
    printf("Welcome To System\nEnter 6 digits Password for system: ");
    scanf("%s",ResPassword);
    while(strlen(ResPassword)!=6)
    {
        printf("password must be 6 digits\nPassword: ");
        scanf("%s",ResPassword);

    }



    while(r==0)
    {

        //get one option and preventing enter key from being a one because of bouncing
        if(option=='\n')
        {

        }
        else
        {
            system("clear");
            printf("**********Welcome to our clink**********\n----------------------------------------\n\n");
            printf("Please choose one mood \n\n1-Admin\n\n2-User\n\n3-Exit program\n");
        }
        scanf("%c",&option);


        if(option=='1')
        {
            //checking password to enter admin mood
            system("clear");
            printf("Please enter password\n");
            while(1)
            {
                    scanf("%s",&Password);
                    for(int i =0 ; i<7 ; i++)
                    {
                        if(Password[i]==ResPassword[i])
                        {
                            c2++;
                        }
                    }
                    if(c2==6)
                    {
                        c2=0;
                        r='1';
                        system("clear");
                        //entering admin mood
                        admin(ptr);
                        counter=0;
                        break;

                    }
                    else
                    {
                        system("clear");
                        c2=0;
                        printf("Password is not correct please enter the correct Password\n");
                        counter++;
                    }
                    //3 wrong trys gets you back to menu
                    if(counter==3)
                    {
                        printf("Too many Wrong Trys");
                        counter=0;
                        break;
                    }




            }


        }
        //user mood
        else if (option=='2')
        {
            r=1;
            user(ptr);
        }

        else if (option=='3')
        {
            exit(1);
        }

        else if (option!='\n')
        {
            printf("Wrong choise please try again\n");
        }



    }
        system("clear");



    return 0;
}


