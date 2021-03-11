/*Solo corre en Code::Blocks, no en el online gbd :( */
/*texto sugerido a utilizar: h,ok.ao97-64(fw.789) "wo78.", [e--soa,.97648]*/
#include<stdio.h>
#define TRUE 1
#define FALSE 0
int main()
{
   char s[100];
   char o[100];
   int p=0;
   int q=0;
   int j=0;
   int i=0;


   scanf("%[^\n]",s);

   while(s[i] != '0')
   {
       switch(s[i]){
           case '(': p=TRUE; o[j] = s [i];
            j++; break;
           case ')': p=FALSE; o[j] = s [i];
            j++; break;
           case '{': p=TRUE; o[j] = s [i];
            j++; break;
           case '}': p=FALSE; o[j] = s [i];
            j++; break;
           case '[': p=TRUE; o[j] = s [i];
            j++; break;
           case ']': p=FALSE; o[j] = s [i];
            j++; break;

           case '\"': q++; o[j] = s [i];
            j++; break;
           case '\'': q++; o[j] = s [i];
            j++; break;

      default:

          if (p==TRUE || q==TRUE){
             o[j] = s[i];
             j++;
            }
          else {                //lines 44-47 taken from rulegamer07
             if (q==2){
                    q=0;}


            if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i] == ' '))
                {
                o[j] = s[i];
                j++;
                }
                else{
                      if(s[i] >=48 && s[i] <=57 ) {
                          if(o[j-1]=='X'){ }
                          else {o[j]='X';
                                j++;}
                         }
                 }
            }
          }
      i++;
    }
   printf("%s\n", o );

   return 0;
}
