#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char **argv){

    int n=atoi(argv[1]);
    for (int i=0;i<n;i++){
        fork();
        sleep(5);
    }
    printf("New fork\n");
    return EXIT_SUCCESS;
}

