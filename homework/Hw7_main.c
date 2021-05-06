/*Incluir los archivos: main.c, functions.h, list.txt. Antes de correr el programa: darle un enter al archivo "list.txt" para que el puntero inicie en la línea 9.
Si imprime la opción 3 "Show attendance records" solo q es necesario darle scroll para arriba para poder visualizar el texto impreso. */
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include<string.h>
#include<math.h>
#include<conio.h>
#include <time.h>
#define NAME 10
#define DAY 10
#define ENTRY 4
#define EGRESS 4
#define NEWNAME 10
#define NEWDAY 10

int anterior;
void crear (void);
void mostrar (void);
void add (void);
void showList (void);


int menu (void){
 printf ("\t\t<<<MENU>>>\n");
 printf ("\t1. Add employee.\n");
 printf ("\t2. Register attendance.\n");
 printf ("\t3. Show attendance records.\n");
 printf ("\t4. Hours worked.\n");
 printf ("\t5. Exit\n\n");
 printf ("Choose an option:  ");
}

int main(int x, char** y) {
  int op;
  int F=0;
  char c;
   int i, count = 0;
   employee** e;
   
 
  
  showList();
  op==menu();
 scanf ("%d", &op);
 printf ("\n\n");
 while (op !=7){
  if (op==1){
   printf ("\nAdd employee.\n");
   add ();
   showList();
   op==menu();
   scanf ("%d", &op);
   
   } 
   
   else{
    if(op==2){
     printf ("\nRegister attendance.\n");
     crear ();
     op==menu();
     scanf ("%d", &op);
     
     
    }
    else{
     if(op==3){
         printf ("\nShow attendance records.\n");
      mostrar ();
      
      op==menu();
      scanf ("%d", &op);
     }
     else {
      if(op==4){
       printf ("\nHours worked.\n"); 
      // horast ();
       op==menu();
       scanf ("%d", &op);
      }
      else {
      if(op==5){
      
       break;
      }
      }
     }
    }
   }
 }

  
  return 0;
}

void crear()
{
  int F=0;
  int terminar;
  anterior=0;
  terminar=0;
   for (F=anterior; F<200&&terminar!=1; F++)
  {
   printf ("Worker ID:\n");
   fflush (stdin);
   scanf ("%s", eRegister[F].idemp);
   printf ("Enter day:\n");
   fflush (stdin);
   scanf ("%s", eRegister[F].workDay);
   printf ("Check-in time:\n");
   fflush (stdin);
   scanf ("%s", eRegister[F].start);
   printf ("Departure time:\n");
   fflush (stdin);
   scanf ("%s", eRegister[F].end);
   printf ("Have you finished registering workers?\n1=Yes\t 2=No");
   scanf ("%d", &terminar);
   anterior==F;
   printf ("\n\n");
  }
   if (anterior==200)
   {
    printf ("\n List is full");
   }
}

void mostrar ()
{
 int F;
 F=0;
 anterior=0;
 printf ("PIN  DAY  START  END   \n--------------------   \n");
 for (F=anterior; F<200; F++)
 {
  
  printf ("%s  ", eRegister[F].idemp);
  printf ("%s ", eRegister[F].workDay);
  printf ("%s ", eRegister[F].start);
  printf ("%s\n ", eRegister[F].end);
  
  anterior==F;
 }
 
}

void add()
{
    int newpin;
    char newday[NEWDAY + 1];
    int newentry;
    int newdeparture;
    int i;
    srand(time(NULL));
    char newname[NEWNAME + 1];
    FILE *list = fopen("list.txt", "a");
    printf("Type new employee name\n");
    scanf("%s", newname);
    printf("Which day does this employee works?");
    scanf("%s", newday);
    newpin = 5 + rand()% (10 + 1);
    newentry = 5 + rand()% (10 + 1);
    newdeparture = newentry + 8;
    fprintf(list, "%d %s %s %d %d\n", newpin, newname, newday, newentry, newdeparture);
    fclose(list);
    
}

void showList()
{
  int op;
  int F=0;
  char c;
   int i, count = 0;
   employee** e;
   
   FILE* list = fopen("list.txt", "r");
   while ((c = fgetc(list)) != EOF) 
   {
     if (c == '\n') 
     {
       count++; // chequemos cuantos van a ser
       
     }
    }
  
  e = (employee**)malloc(sizeof(employee*) * count);
  rewind(list); // regresamos al inicio
  for (i = 0; i < count; i++) 
  {
    e[i] = (employee*)malloc(sizeof(employee));
    e[i]->name = (char*)malloc(sizeof(char) * (NAME + 1));
    e[i]->day = (char*)malloc(sizeof(char) * (DAY + 1));
    e[i]->entry = (char*)malloc(sizeof(char) * (ENTRY + 1));
    e[i]->egress = (char*)malloc(sizeof(char) * (EGRESS + 1));
    fscanf(list, "%u %s %s %s %s", &(e[i]->pin), e[i]->name, e[i]->day, e[i]->entry, e[i]->egress);    
  }
  
  
  fclose(list);
  for (i = 0; i < count; i++) {
    printf("Employee %u %s works on %s, from %s to %s \n", e[i]->pin, e[i]->name, e[i]->day, e[i]->entry, e[i]->egress);
    
    free(e[i]->name);
    free(e[i]->day);
    free(e[i]->entry);
    free(e[i]->egress);
    free(e[i]);
  }
  free(e);
 }

 

