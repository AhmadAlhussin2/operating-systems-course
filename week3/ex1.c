#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int age)
{
    int result;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    result=(1900+tm.tm_year) - age;
    return result;
}

int main()
{
    const int x=10;
    const int* q=&x;
    const int* const p = malloc(5*sizeof(const int*));
    for (int i=0; i<5; i++)
    {
        int* pp = (p+i);
        *pp=x;
    }
    for (int i=0; i<5; i++)
    {
        fprintf(stdout,"%p ",(p+i));
    }
    fprintf(stdout,"\n");
    for (int i=0; i<5; i++)
    {
        int age;
        fscanf(stdin,"%d",&age);
        int* pp = (p+i);
        *pp=age;
    }
    for (int i=0; i<5; i++)
    {
        int birthYear = foo(*(p+i));
        int *pp = (p+i);
        *pp = birthYear;
    }
    free(p);
    return 0;
}
