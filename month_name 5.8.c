#include <stdio.h>

char *month_name(int n)
{
  static char *name[] = {
    "Illegal month",
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
  };
  return (n < 1 || n > 12) ? name[0] : name[n];
}

void indirect_call_function(char* (*fptr)(int n))
{
  fptr(1);
}

int main()
{

  printf("%s\n", month_name(10)); // print string
}
