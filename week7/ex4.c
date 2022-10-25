#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include <malloc.h>

size_t min(size_t x,size_t y){
    if (x<y)return x;
    return y;
}
void* reallocate(void* arr,size_t size){
    if (arr==NULL)return malloc(size);
    if (size==0){
        free(arr);
        return NULL;
    }
    void* arr2 = malloc(size);
    memcpy(arr2,arr,min(malloc_usable_size(arr),size));
    free(arr);
    return arr2;
}

int main(){
    int n;
    scanf("%d",&n);
    int* arr=malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        arr[i]=i;
    }
    arr=reallocate(arr,5*sizeof(int));
    for (int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}
