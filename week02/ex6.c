#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    scanf("%d",&num);
    printf("First pattern:\n");
    for (int i=0; i<num; i++)
    {
        for (int j=0; j<num; j++)
        {
            if (j<=i)
            {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("Second pattern:\n");
    int t=num;
    for (int i=0; i<num; i++)
    {
        t--;
        for (int j=0; j<num; j++)
        {
            if (i<(num+1)/2&&j<=i)
            {
                printf("*");
            }
            else if (i>=(num+1)/2&&j<=t)
            {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("Third Pattenr:\n");
    for (int i=0; i<num; i++)
    {
        for (int j=0; j<num; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

