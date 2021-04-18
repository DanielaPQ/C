#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int day, int *pmonth, int *pday);

int main(void)
{
    int year, day;
    int a, b;
    int *pmonth = &a;
    int *pday = &b;

    printf("please input the year and the day:");
    scanf("%d%d", &year, &day);
    month_day(year, day, pmonth, pday);
    if (*pmonth < 0 || *pday < 0) {
        printf("error: input over the range!");
    }
    else
        printf("the %d day of %d is month %d and day %d \n",day, year, *pmonth, *pday);


    return 0;
}

/* month_day: set month, day from day of year */
void month_day(int year, int day, int *pmonth, int *pday)
{
    int i, leap;
    char *p;

    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    leap = (year % 4==0 && year % 100 != 0) || year % 400 ==0;

    p = *daytab;
    i = 1;

    while (day > *++p) {
        day -= *p;
        i++;
        if (i > 12) {
            *pmonth = -1;
            *pday = -1;
            return;
        }
    }


        *pmonth = i;
        *pday = day;

}
