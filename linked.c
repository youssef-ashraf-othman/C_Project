#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"
typedef struct Node
{
    char name[50];
    int age;
    char gender[50];
    int id;
    char slot[50];
    int value;
    struct Node *Next;


}Node;


Node *head=NULL;
Node *current=NULL;
Node *temp=NULL;
Node *result=NULL;




//for adding a patient in linked list
void Add_Patient(char name[],int age,char gender[],int id)
{

    temp=(Node*)malloc(sizeof(Node));
    if(head==NULL)
    {
        head=temp;
        head->Next=NULL;
        strcpy(head->name,name);
        head->age=age;
        strcpy(head->gender,gender);
        head->id=id;
        strcpy(head->slot,"None");
        head->value=0;


    }
    else
    {
        current=head;
        while(current->Next!=NULL)
        {
            current=current->Next;
        }
        current->Next=temp;
        temp->Next=NULL;
        strcpy(temp->name,name);
        temp->age=age;
        strcpy(temp->gender,gender);
        temp->id=id;
        strcpy(temp->slot,"None");
        temp->value=0;
        current=NULL;


    }

}






//for searching id
int Search(int pid)
{

    int c=0;
    temp = head;

    while(temp != NULL)
    {
        if(temp->id == pid)
        {
            c++;
            break;

        }
        temp = temp->Next;
    }

   result=temp;
   return c;

}
//adding slot after reservation is canceld
int add_slot()
{

    strcpy(result->slot,"None");
    int x =result->value;
    result->value=0;
    return x;
}
//adding the slot time to the info of patient
void reserve_slot(int option,char slot[])
{
    result->value=option;
    strcpy(result->slot,slot);
}
//check for available slots
int check()
{
    int c=0;
    if(result->value!= 1 && result->value!= 2 &&  result->value!= 3 &&  result->value!= 4 &&  result->value!= 5)
    {
       c++;
    }
    return c;
}


//print info of patient
void printList()
{


    if(result==NULL)
    {
        printf("There is no Such Id\n");
        printf("-------------------\n");

    }
    else
    {
        printf("Name:%s\n\nAge:%d\n\nGender:%s\n\nId:%d\n\nReservation time : %s\n-----------------------------\n",result->name,result->age,result->gender,result->id,result->slot);

    }

}





//edit info of patient
void Edit(int id)
{


    int new_id=0,new_age=0;
    char new_name[50];
    char new_gender[50];
    char s,option;
    int c = Search(id),r=0;
        if(c==1)
        {
            printf("Id Founded\n");
            printList();
            
            while(1)
            {
                printf("Choose what to edit\n\n1-Name\n\n2-Age\n\n3-Gender\n\n4-Id\n\n5-Back to last menu\n\n");
                while(option!='1' && option!='2' && option!='3' &&  option!='4' &&  option!='5')
                {
                    scanf("%c",&option);
                }
                if(option=='1')
                {
                    option='0';
                    system("clear");
                    printf("Enter new Name\n");
                    scanf("%s", new_name);
                    int i = strlen(new_name);
                    do
                    {
                        scanf("%c", &s);
                        new_name[i++] = s;
                    }while (s != '\n');
                    new_name[i - 1] = 0;
                    strcpy(temp->name,new_name);
                    system("clear");
                    printf("**Name has been updated**\n---------------------\n");
                    printList();
                }
                else if(option=='2')
                {
                    option='0';
                    system("clear");
                    printf("Enter new age\n");
                    while(1)
                    {
                        scanf("%d",&new_age);
                        break; 
                        
                    }
                    if(new_age=='0' || new_age==0)
                    {
                        new_age=0;
                        printf("Age Can't be zero or characters only numbers\n");
                        printf("--------------------------------------------\n");
                        printList();
                    }
                    else
                    {
                        temp->age=new_age;
                        new_age=0;
                        system("clear");
                        printf("**Age has been updated**\n---------------------\n");
                        printList();
                    }
                }
                else if(option=='3')
                {
                    option='0';
                    system("clear");
                    printf("Enter new Gender\n");
                    scanf("%s",&new_gender);
                    strcpy(temp->gender,new_gender);
                    system("clear");
                    printf("**Gender has been updated**\n---------------------\n");
                    printList();
                }
                else if(option=='4')
                {
                    option='0';
                    system("clear");
                    printf("Enter new Id\n");
                    while(1)
                    {
                        scanf("%d",&new_id);
                        break;
                    }
                    if(new_id=='0' || new_id==0)
                    {
                        new_id=0;
                        printf("ID Can't be zero o characters only numbers\n");
                        printf("--------------------------------------------\n");
                        printList();
                    }
                    else
                    {
                    
                        temp->id=new_id;
                        new_id=0;
                        system("clear");
                        printf("**Id has been updated**\n----------------------\n");
                        printList();
                    }
                }
                else if(option=='5')
                {
                    option='0';
                    break;
                }
            }


        }
        else
        {
        system("clear");
        printf("There is no Such Id\n-------------------\n");
        }


}












