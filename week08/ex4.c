#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main(){
    size_t size=10*1024*1024;
    for (int t=0;t<10;t++){
        int *ptr=malloc(size);
        memset(ptr,0,size);
        struct rusage usage;
        getrusage(RUSAGE_SELF,&usage);
        printf("%ld\n",usage.ru_maxrss);
        sleep(1);
    }
}
