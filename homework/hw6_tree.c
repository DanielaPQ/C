#include <stdio.h> // printf
#include <stdlib.h> // malloc & free
#include <ctype.h> // isspace & tolower
#include <string.h> // strlen
#include "tree.h"
#define MAX_LENGHT 10

//erase branches then node
void erase(node* pos) {
  if (pos != NULL) {
    erase(pos->leftChild);
    erase(pos->rightChild);
    free(pos);
  }
  return;
}

node* insert(char* u, char* p, node* pos, int d) {
  node* temp;
  int a;
  
  
 
  if (pos == NULL) {
      
    pos = (node*)malloc(sizeof(node));
    pos->username = u;
    pos->password = p;
    pos->depth = d;
    
    printf( "Succesfully registered %s %s \n", u, p);
    
    } 
    else 
    {
        if (strcmp(pos->username, u) == 0)
        {
          if (pos->password != NULL)
          {
              printf("Existing user, try again \n ");
              printf( " %s %s \n", u, p);
           }   
           else
           {
               pos->password = p;
               printf( "BSuccesfully registered %s %s  \n", u, p);
            }
        }else if (strcmp(pos->username, u)> 0) 
              { /*Smaller*/
                temp = insert(u, p, pos->leftChild, d + 1);
                if (pos->leftChild == NULL) 
                {
	                pos->leftChild = temp;
                }
              } else if (strcmp(pos->username, u)<0)
                     {
                        temp = insert(u, p, pos->rightChild, d + 1); /*Larger*/
                        if (pos->rightChild == NULL) {
	                    pos->rightChild = temp;
                     }
    
    }
 }
    
  return pos;
}


//in alphabetical order
void alpha(node* position) {
  if (position != NULL) {
    alpha(position->leftChild);
    if (position-> password != NULL){
    printf("%s", position->username);
    }
    alpha(position->rightChild);
  }
}