#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

void admin(int *ptr);
void user(int * ptr);
void Add_Patient(char name[50],int age,char gender[50],int id);
int Search(int pid);
void Edit(int id);
void printList();
int add_slot();
void Slot_List();
void delete_Node(int key);
void Reserve();
void addLast(int x,char new_slot[50]);
void reserve_slot(int option,char slot[]);
int check();
sortList();


#endif
