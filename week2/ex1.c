#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <stdio.h>

int main()
{
    int x1=INT_MAX;
    unsigned short int x2=USHRT_MAX;
    signed long int x3=LONG_MAX;
    float x4=FLT_MAX;
    double x5=DBL_MAX;
    printf("maximum value for integer is: %d and its size: %zu\n",x1,sizeof(x1));
    printf("maximum value for unsigned short integer is: %hu and its size: %zu\n",x2,sizeof(x2));
    printf("maximum value for long integer is: %ld and its size: %zu\n",x3,sizeof(x3));
    printf("maximum value for float is: %f and its size: %zu\n",x4,sizeof(x4));
    printf("maximum value for double is: %lf and its size: %zu\n",x5,sizeof(x5));
    return 0;
}
