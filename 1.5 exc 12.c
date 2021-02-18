#include <stdio.h>

main()
{
    int c, linestarted;
    linestarted = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n') {
            if (!linestarted) {
                putchar('\n');
                linestarted = 1; }
        } else {
            putchar(c);
            linestarted = 0;
        }
    return 0;
}
