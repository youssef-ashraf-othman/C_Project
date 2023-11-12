# Clinic Reservation System

Clinic reservation system is a system that facilitates the process of reservation.
At the start of program, he will ask you to enter password for your admins to only give the access 
to them. Then he will ask you to choose one of two moods.
## 
### Frist Mood (Admin Mood):
This mood requires a password to pass you to the control panel. In control panel you can control your system as it gives you many options:

1- Add patient record: to add information of a patient to system.
This information contains patient's name, patient age, patient's gender, and Patient's Special Id.

2- Edit Patient record: you can easily edit Patient's info, by entering his id it will give you the access to edit any information about him after searching for him in system.

3- Reserve with doctor: in this field you will see 5 time slots to reserve the one which is suitable for you.
You can reserve any time slot with only entering the id of patient.
once you reserve one, this slot will not appear again until you cancel this reservation. 

4- Cancel Reservation: If you want to cancel a reservation you can do that here by entering the id of patient. When you cancel a reservation the time slot is back again so any can reserve it. 


### Second Mood (User Mood): 
From its name it's user mood it doesn't require any password to enter it. It allows any user to know if he is on system or not and if he is on system the program will give him all his information and reservation time if he have reserved before. This can be done by entering his id.

## 
### Used Technologies:
This project is mainly based on single linkedlist.
I have used two single linked lists, one to store the information of patients, and the other to store time slots to allow me to delete and restore the slots easily.
ID is the Key to the list of patients. If I want to find any node, I simply use the Id as The Id cannot be repeated by any two patients.

##
###Challenges that faced me:
The biggest challenge was how to handle if someone entered a character instead of a number when he chooses one of options in the program.
To be known when you do that when you expect a number the program will go for infinity loop if "scanf" statement is within a loop.
I couldn't easily let the user to enter characters in some fields that cannot be characters like age, and Id.
I had to force him to enter integers.
This doesn't mean that I didn't use a characters instead of integers in some options like the ones which the user use to enter any menu but, it leads to another problem which is the bouncing of enter key that the program reads it as an input besides the real input so I had to deal with it also.
##
### Features I want too add in the future : 
1- Making a GUI to the program to make it more Easier to use 
2- Expanding the options of admin, user, and time slots of course 

