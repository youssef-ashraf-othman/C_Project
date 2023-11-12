#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void admin (int *ptr )
{
    char slots[5][20] ={"2pm to 2:30pm","2:30pm to 3pm","3pm to 3:30pm","3:30pm to 4pm","4pm to 4:30pm"};
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
    int age=0,NoOfSlots=5,c,k,r=0;
    char StringSpacing;
    int id=0,option2;
    char option;
    char name[20];
    char gender[20];
    printf("welcome to adminstration section\n-------------------------------\nChoose one of this options:\n\n");
    //get one option and preventing enter key from being a one because of bouncing
    while (1)
    {
        if(option!='\n')
        {

        }
        else
        {
            printf("1-Add patient record\n\n2-Edit patient record\n\n3-Reserve a slot with the doctor\n\n4-Cancel reservation\n\n5-Back to main menu\n");
        }
        scanf("%c",&option);
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
        //option 1 to add patient
        if(option=='1')
        {
            system("clear");
            printf("Enter the name of patient:\n");
            //to enter space in name without problems
            scanf("%s",name);
            int i = strlen(name);
            do
            {
                scanf("%c", &StringSpacing);
                name[i++] = StringSpacing;
            } while (StringSpacing != '\n');
            name[i - 1] = 0;
            //entering the rest of paramters
            //----------------------------------------------------------------------------------------
            //----------------------------------------------------------------------------------------
            printf("Enter the age of patient:\n");
            //To handle if someone entered age characters
            while(1)
            {
                scanf("%d",&age);
                break;
            }
            //to know if age wrongly entered
            if(age==0 || age=='0')
            {
                age=0;
                
                system("clear");
                printf("age can't be zero or characters only numbers\n");
                printf("-------------------------------------------\n");
            }
            else
            {
                printf("Enter the gender of patient:\n");
                scanf("%s",&gender);
                printf("Enter the id of patient:\n");
                //to handle if someone entered id in characters
                while(1)
                {
                        scanf("%d",&id);
                        break;
                }
                //search for id to know if it was used before or it's wrongly entered
                if(id==0 || id=='0')
                {
                    id=0;
                   
                    system("clear");
                    printf("Id can't be zero or characters only numbers\n");
                    printf("-------------------------------------------\n");
                }
                else
                {
                    c = Search(id);
                    if(c==0)
                    {
                        Add_Patient(name,age,gender,id);
                        id=0;
                        age=0;
                        system("clear");
                        printf("**Patient has been added**\n--------------------------\n");
                    }
                    else
                    {
                        system("clear");
                        printf("Id  is already used\n------------------\n");
                    }
                }



            }



        }
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
        //option 2 to edit patient info by giving his id
        else if(option=='2')
        {
            system("clear");
            printf("Enter id of patient you want to edit his info\n");
            scanf("%d",&id);
            Edit(id);
            
            
        }
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
        //option 3 to reserve a slot with the doctor
        else if(option=='3')
        {


            system("clear");
            printf("Enter Id of patient:\n");
            //To handle if someone entered Character
            while(1)
            {
                scanf("%d",&id);
                break;
            }
                //search for id to know if it was used before or it's wrongly entered
            if(id==0 || id=='0')
            {
                id=0;
                system("clear");
                printf("Wrong Id\n--------\n");
            }
            else
            {
                system("clear");
                c = Search(id);
                if(c=='0')
                {
                    printf("Id  not found,please try again\n------------------------------\n");
                }
                else
                {
                    //check if the id has reserved before or not
                    k=check();
                    if(k==1)
                    {
                        //check if there is slots haven't been reserved yet
                        if(NoOfSlots>0)
                        {
                            //system("clear");

                            while(1)
                            {
                                sortList();
                                Slot_List();

                                scanf("%d",&option2);
                                if(option2 != 1 && option2 != 2 && option2 != 3 && option2 != 4&& option2 != 5)
                                {
                                    system("clear");
                                    printf("Wrong option\n");

                                }
                                else
                                {
                                    system("clear");
                                    //deleting the node that has been reserved
                                    reserve_slot(option2,slots[option2-1]);
                                    delete_Node(option2);
                                    NoOfSlots--;
                                    printf("Reservation Completed!\n-----------------------\n");
                                    break;
                                }

                            }
                        }

                        else
                        {
                            printf("Sorry all slots are reserved\n-------------------------------------\n");
                        }

                    }
                    else
                    {
                        printf("Id has already reserved before\n-----------------------\n");
                    }


                }

            }




        }
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
        //option 4 to cancel reservation using id
        else if(option=='4')
        {
            system("clear");
            printf("Enter Id of patient\n");
            //To handle if someone entered Character
            while(1)
            {
                scanf("%d",&id);
                break;
            }
                //search for id to know if it was used before or it's wrongly entered
            if(id==0 || id=='0')
            {
                id=0;
                 system("clear");
                printf("Wrong Id\n--------\n");
            }
            else
            {
                system("clear");
                c =Search(id);
                if(c==0)
                {
                    printf("There is no such id\n-------------------\n");
                }
                else
                {
                    //adding back the slot node again
                    int l = add_slot();
                    if(l!=0)
                    {
                         addLast(l,slots[l-1]);
                         NoOfSlots++;
                         printf("Reservation has been canceled\n-----------------------------\n");
                    }
                    else
                    {
                        printf("Id has no reservation\n---------------------\n");

                    }

                }

            }
        }
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
        //option 5 to go to main menu
        else if(option=='5')
        {

            *ptr=0;
            break;
            system("clear");
        }
/*----------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------*/
        else if(option!='\n')
        {
            system("clear");
            printf("Wrong option please try again\n----------------------------\n");
        }


   }


}
