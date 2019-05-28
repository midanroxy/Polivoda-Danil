#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main ()
{
    int secondWord = 0;
    char s[50];
    char *p;
    p=gets(s);

    for (p = s; *p; ++p)
    {
        if (isspace(*p) && secondWord)
        {
            secondWord = 0;
        }
        else if(isspace(*p) && !secondWord)
        {
            secondWord = 1;
        }
        else if(!isspace(*p) && secondWord)
        {
            strncpy(p, "*", sizeof(*p));
        }
    }
    printf("\nEntestring: %s. ",s);

    return 0;
}
