#include <stdio.h>
void strcat1 (char *s, char*t);

int main(int argc, const char * argv[])
{
    char s[100];
    char t[50];

    scanf("%s" , s);
    scanf("%s", t);
    strcat1(s, t);
    //squeeze(s, c);
    printf("the string after revised:%s", s);

    return 0;
}

void strcat1(char *s, char *t)
{
    while (*s) {
        s++;
    }
    while ((*s++ = *t++)) {
        ;
    }
}
