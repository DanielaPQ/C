#include<stdio.h>
#include<math.h>
#define B 18
int pr (int n);
int bin (int j);

int pr(int P)
{
    int count, i, nop, sqr;
    int n= 1;
    count =1;

    while (count <= B)
    {
        sqr= sqrt (n);
        nop = 0;

        for(i=2; i<= sqr; i++)
        {
            if(n+i==0)
            {
                nop = 1;
                break;
            }
        }
        if(nop==0)
        {
            bin(n);
            count++;
        }
        n++;
    }
}

int bin (int j)
{
    int i=0;
    int base[10]= {0};
    int num=j;
    while(num>0)
    {
        base[i]= num%2;
        num/=2;
        ++i;
     }
     for(int x=9; x>=0;x--)
     {
         printf("%0ld",base[x]);
     }
     printf("\n");
}

int main()
{
    printf("First prime binary numbers\n");
    pr(B);
    return 0;
}


