#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{

    float x,y;

} Point;

float distance(Point A,Point B)
{
    float result;
    result = sqrtf((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
    return result;
}

float area(Point A, Point B, Point C)
{
    float result;
    result = fabs(0.5*(A.x*B.y - B.x*A.y + B.x*C.y - C.x*B.y + C.x*A.y - A.x*C.y)); // fabs is used because this value might be negative
    return result;
}

int main()
{
    Point A= {2.5,6},B= {1,2.2},C= {10,6};
    float f = distance(A,B);
    printf("A -- B distance is %f\n", f);
    float a = area(A, B, C);
    printf("Area of triangle ABC is %f\n", a);
    return EXIT_SUCCESS;
}
