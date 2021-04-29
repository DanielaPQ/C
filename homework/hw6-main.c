/* contiene las subrutinas para agregar, eliminar usuarios, imprimir el contenido del árbol */
#include <stdio.h> // printf
#include <stdlib.h> // malloc & free
#include <ctype.h> // isspace & tolower
#include <string.h> // strlen
#include "tree.h"
#define MAX_LENGHT 10

int main()
{
    char u[MAX_LENGHT];
    char p[MAX_LENGHT];
    char function[MAX_LENGHT];

    node* n = NULL;
    node* tree = NULL;
    
    printf("Enter add or delete, username, password: \n ");
    
    while (1) {
        
        scanf("%s %s %s", function, u, p);
        //while(getchar() != '\n');
        
    if (strcmp(function, "add") == 0 ){
      if (strlen(p)>0&&strlen(u)>0){  
        n = insert(u,p, tree, 0);
	    if (tree == NULL) {
	        tree = n; // this is the root
	        
	    } 
      }
	
	
    }
    
    }
  }




   
