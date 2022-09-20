#include <stdio.h>
#include <stdlib.h>


void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b)
{

    (*((int*)a))+=(*((int*)b));
    return a;
}

void* addDouble(const void* a, const void* b)
{

    (*((double*)a))+=(*((double*)b));
    return a;
}

void* mulInt(const void* a, const void* b)
{

    (*((int*)a))*=(*((int*)b));
    return a;
}

void* mulDouble(const void* a, const void* b)
{
    (*((double*)a))*=(*((double*)b));
    return a;
}

void* meanInt(const void* a, const void* b)
{

    ((*((int*)a))+=(*((int*)b)));
    ((*((int*)a)))/=2;
    return a;
}

void* meanDouble(const void* a, const void* b)
{

    ((*((double*)a))+=(*((double*)b)));
    ((*((double*)a)))/=2;
    return a;

}

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*))
{

    void* output;

    if (size==sizeof(int))  // base is a pointer to an integer
    {
        int ret=*((int*)initial_value);
        for (int i=0;i<n;i++){
            ret=(*((int*)opr(&ret,base+sizeof(int)*i)));
        }

        output=(&ret);

    }
    else   // base is a pointer to a double
    {

        double ret=*((double*)initial_value);
        for (int i=0;i<n;i++){
            ret=(*((double*)opr(&ret,base+sizeof(double)*i)));
        }

        output=(&ret);

    }

    return output;
}




int main()
{

    int* ints = malloc(sizeof(int)*5);
    double* doubles = malloc(sizeof(double)*5);

    ints[0]=1;
    ints[1]=3;
    ints[2]=4;
    ints[3]=2;
    ints[4]=5;

    doubles[0]=1.38;
    doubles[1]=2.24;
    doubles[2]=3.72;
    doubles[3]=7.01;
    doubles[4]=5.21;

    // Addition
    int* result1a;
    int initialValue1=0;
    result1a = aggregate(ints,sizeof(ints[0]),5,&initialValue1,addInt);

    printf("%d\n", *result1a);

    double* result2a;
    double initialValue2=0;
    result2a = aggregate(doubles,sizeof(doubles[0]),5,&initialValue2,addDouble);

    printf("%f\n", *result2a);


    // Multiplication

    int* result1m;

    int initialValue3=1;
    result1m = aggregate(ints,sizeof(ints[0]),5,&initialValue3,mulInt);

    printf("%d\n", *result1m);

    double* result2m;

    double initialValue4=1;
    result2m = aggregate(doubles,sizeof(doubles[0]),5,&initialValue4,mulDouble);

    printf("%f\n", *result2m);



    // Mean

    int* result1mean;

    int initialValue5=0;
    result1mean = aggregate(ints,sizeof(ints[0]),5,&initialValue5,meanInt);

    printf("%d\n", *result1mean);

    double* result2mean;

    double initialValue6=0;
    result2mean = aggregate(doubles,sizeof(doubles[0]),5,&initialValue6,meanDouble);

    printf("%f\n", *result2mean);


    free(ints);
    free(doubles);

    return EXIT_SUCCESS;
}
