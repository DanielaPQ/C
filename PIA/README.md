# Hotel front desk
This program is designed to perform the functions of check-in, check-out of a hotel.
In order to execute the program we must add "main.c", "functions.h" and "guests.c", which is empty.

## How to use it
The first thing that will appear on the screen will be the menu which has 3 options: 1.-Reserve room, 2.-Pay and 3.-Exit.
We first select 1 (Reserve room), the program will verity if there is availability, in which case it will then ask to type a name an a password and it will then ask 3 
questions and tell their respective cost then it will assing the user a room number. The maximum number of rooms is 5, so if we try to register a 6th person the program will tell
us there is no vacancy and it will stop.
The second option (Pay) will ask to enter a user with its respective password, in the case they don't match the program will tell so, and if they do match it will be shown the total debt followed by the text "Enter amount" which is the quantity with which we pay, if it is less than the debt, this will keep showing till there's no debt, and if it is more than the actual debt it will give us our change.
The third option (Exit) will take us out of the program.

## Bibliography
https://github.com/satuelisa/C/blob/main/Ch7/archivo.c
https://github.com/DanielaPQ/C/blob/main/homework/Hw7_main.c
