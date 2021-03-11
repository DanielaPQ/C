#include<stdio.h>
int main()
{
   char s[100];
   char o[100];
   int p=0;
   int j=0;
   int i=0;

   //printf("Enter a string:");
   scanf("%[^\n]",s);

   while(s[i]!='\0')
   {
      if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i] == ' '))
      {
      o[j] = s[i];
      j++;
      }
      //else{
          //o[j] = '';

     else{  if(s[i] >=48 && s[i] <=57 )
      {
          if(o[j-1]=='X'){
             // printf("X");
          }
          else {o[j]='X';
                j++;}

      }}
      i++;



   }

   printf("%s\n", o );


   return 0;
 }
