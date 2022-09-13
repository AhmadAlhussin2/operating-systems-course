#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str[257];
    int len=0;
    fgets(str,257,stdin);
    for (int i=0; i<strlen(str); i++)
    {
        if (str[i]=='.'||str[i]=='\n')
        {
            break;
        }
        len++; //count the number of characters before the dot or line end
    }
    putchar('"');
    for (int i=len-1; i>=0; i--) // iterate from the point we stopped till the begging to print them in reverse order
    {
        putchar(str[i]);
    }
    putchar('"');
    putchar('\n');
    return 0;
}

