#include <stdlib.h>
#include <stdio.h>

long long tribonacci(int num)
{
    long long a=0,b=1,c=1; // first three values of Tribonacci
    if (num==0)
    {
        return 0;
    }
    else if (num<=2)
    {
        return 1;
    }
    else
    {
        for (int i=3; i<=num; i++)
        {
            // let a be Tribonacci[i-3], b be Tribonacci[i-2], and c be Tribonacci[i-1]
            long long current=a+b+c; // now we can know that Tribonacci[i] = a+b+c
            //shift the numbers a,b,c to the new place
            a=b;
            b=c;
            c=current;
        }
        return c;
    }
}


int main()
{
    printf("%lld %lld\n",tribonacci(4),tribonacci(36));
}
