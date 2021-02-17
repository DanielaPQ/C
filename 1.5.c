#include<stdio.h>
main()
{
    int c;
    while ((c = getchar()) != EOF){
        printf(" The value of getchar() != EOF is %d.\n",
               (c != EOF));
               getchar();
    }
    printf("The value of getchar() != EOF is %d.\n",
           (c != EOF));
           return 0;
}
