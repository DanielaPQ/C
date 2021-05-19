#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"
#define NAME 30
#define PASSWORD 20
#define ROOM 5
#define AMOUNT 3


int previous;
int create();
int disp(int x);
int pay();

int menu()
{
 printf ("MENU\n");
 printf ("1. Reserve room\n");
 printf ("2. Pay.\n");
 printf ("3. Exit\n\n");
 printf ("Choose an option:  ");
}

int main()
{
    int op;
    int v;

    op == menu();
    scanf("%d", &op);
    printf("\n");

    while(1)
    {
        if(op==1)
        {
          v = create ();
          if(v==0)
          {
          op == menu();
          scanf("%d", &op);
          }
          else
          {
              op = 3;
          }

        }
        else
        {
            if(op==2)
            {

              pay();
              op == menu();
              scanf("%d", &op);
              printf("\n");
            }
            else
            {
                if(op==3)
                {
                    break;
                }
            }
        }
    }

    return 0;
}


int create()
{
    int r=0;
    char name[NAME + 1];
    char password[PASSWORD + 1];
    char roomamount[AMOUNT + 1];
    char viewamount[AMOUNT];
    char bfamount[AMOUNT + 1];
    int roomNum;
    int occupied;
    int *op;
    int count = 0;
    char c;
    int i;

    FILE* guests = fopen("guests.txt", "r");
    while((c = fgetc(guests)) != EOF)
    {
        if (c == '\n')
        {
            count++;
        }
    }
    rewind(guests);

   if (count<ROOM)
   {
       srand(time(NULL));
       FILE *guests = fopen("guests.txt", "a");
       printf("Enter name. Example: LuisMoreno\n");
       fflush (stdin);
       scanf("%s", name);
       printf("Enter password\n");
       fflush(stdin);
       scanf("%s", password);
       printf("Do you want a single($300) or doble($500) room?\nTyepe 300 for single or 500 for double\t");
       fflush (stdin);
       scanf("%s", roomamount);
       printf("Do you prefer sea view? ($50)\nType 50 for yes or 0 for no\t");
       fflush (stdin);
       scanf("%s", viewamount);
       printf("Do you want a continental breakfast? ($150)\nType 150 for yes or 0 for no\n");
       scanf("%s", bfamount);

       if (count == 0)
       {
        roomNum= 1;
        fprintf(guests, "%d %s %s %s %s %s\n", roomNum, name, password, roomamount, viewamount, bfamount);
        printf("Your room is:%d \n", roomNum);
        } else
          {
            do
            {
            roomNum= 2 + rand()% (5);
            } while (disp(roomNum) == 1);
            fprintf(guests, "%d %s %s %s %s %s\n", roomNum, name, password, roomamount, viewamount, bfamount);
            printf("Your room is:%d \n", roomNum);
        }

       fclose(guests);
       printf ("Successful Registration\n");
       return 0;
   }
   else
   {
        printf ("There's no vacancy\n");
        return 1;
   }

}

int disp(int x)
{
    char c;

    FILE* guests = fopen("guests.txt", "r");

    while((c = fgetc(guests)) != EOF)
    {


        if((int)(c) == x)
        {
            return 1;

        } else
        {
            return 0;
        }
    }

    fclose(guests);

}

int pay()
{
    char desname[NAME];
    char despassword [PASSWORD];
    int xrNum;
    char xame[NAME];
    char xassword [PASSWORD];
    int rxamount;
    int vxamount;
    int bxamount;
    int total;
    int i, m;
    int payment, change, ddebt;
    int sumpay = 0;

    printf("Type username: \n");
    fflush(stdin);
    scanf("%s", desname);
    printf("Type your password: \n");
    fflush(stdin);
    scanf("%s", despassword);
    FILE* guests = fopen("guests.txt", "r");
    for(i = 1; i<=5; i++)
    {
        m = 0;
    fscanf(guests, "%i", &xrNum);
    fscanf(guests, "%s", &xame);
    fscanf(guests, "%s", &xassword);
    fscanf(guests, "%d", &rxamount);
    fscanf(guests, "%d", &vxamount);
    fscanf(guests, "%d", &bxamount);

    if( (strcmp (desname, xame) == 0) && (strcmp (despassword, xassword) == 0))
    {
        total = rxamount + vxamount + bxamount ;
        printf("Debt: $%d\n", total);
        do
        {
          printf("Enter amount: $");
          scanf("%d", &payment);
          sumpay = sumpay + payment;
          change = abs(sumpay - total);

          ddebt = total - sumpay;

        } while(ddebt > 0);
        printf("Change: $%d\n", change);
        //if( total == 0)
        //{

        //}
        break;
    } else
    {
        m = 1;
    }
    }
    if(m == 1)
    printf("\nNO MATCH\n");
}




