#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char data[50];
    int value;
    struct Node *next;
}Node;


Node *head3=NULL;


//creating nodes of time slots
void Reserve()
{

Node *head2 = (Node*)malloc(sizeof(Node));
strcpy(head2->data,"2pm to 2:30pm");
head2->value=1;
head2->next = NULL;

Node *Node2 = (Node*)malloc(sizeof(Node));
strcpy(Node2->data,"2:30pm to 3pm");
Node2->value=2;
Node2->next = NULL;
head2->next = Node2;

Node *Node3 = (Node*)malloc(sizeof(Node));
strcpy(Node3->data,"3pm to 3:30pm");
Node3->value=3;
Node3->next = NULL;
Node2->next = Node3;

Node *Node4 = (Node*)malloc(sizeof(Node));
strcpy(Node4->data,"3:30pm to 4pm");
Node4->value=4;
Node4->next = NULL;
Node3->next = Node4;

Node *Node5 = (Node*)malloc(sizeof(Node));
strcpy(Node5->data,"4pm to 4:30pm");
Node5->value=5;
Node5->next = NULL;
Node4->next = Node5;
head3=head2;
}

//printing available time slots
void Slot_List()
{

    Node *current2= head3;

    while(current2 != NULL)
    {
         printf("%d- %s\n\n",current2->value,current2->data);
         current2 = current2->next;
    }

}
//deleting time slots in case of reserving
void delete_Node(int key)
{

      Node *temp;
      if(head3->value == key)
      {
          temp = head3;
          head3 = head3->next;
          free(temp);
      }

      else
      {
          Node *current  = head3;
          while(current->next != NULL)
          {

              if(current->next->value == key)
              {
                  temp = current->next;
                  current->next = current->next->next;
                  free(temp);
                  break;
              }
              else
                  current = current->next;
          }
      }


}

//getting time slot back when reservation is canceld
void addLast(int x,char new_slot[])
{

    Node *temp=(Node*)malloc(sizeof(Node));
    if(head3==NULL)
    {
        head3=temp;
        head3->next=NULL;
        strcpy(head3->data,new_slot);
        head3->value=x;


    }
    else
    {
        Node *current=head3;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=temp;
        temp->next=NULL;
        strcpy(temp->data,new_slot);
        temp->value=x;


    }

}
//sorting time slots
void sortList()
{

        Node *current = head3, *index = NULL;
        int temp;
        char temp2[20];

        if(head3 == NULL) {
            return;
        }
        else {
            while(current != NULL) {

                index = current->next;

                while(index != NULL) {

                    if(current->value > index->value) {
                        temp = current->value;
                        strcpy(temp2,current->data);
                        current->value = index->value;
                        strcpy(current->data,index->data);
                        index->value = temp;
                        strcpy(index->data,temp2);
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
}




