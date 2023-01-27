#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(void)
{
    pid_t pid1=fork();
    clock_t t1=clock();
    if (pid1==0){
        printf("child1 pid is: %d and its parent pid is: %d and its execution time in milliseconds is: %lf\n",(int)getpid(),(int)getppid(),(((double)clock()-t1)/CLOCKS_PER_SEC*1000));
    }
    else if (pid1>0){
	wait(NULL);
        pid_t pid2=fork();
        clock_t t2=clock();
        if (pid2==0){
            printf("child2 pid is: %d and its parent pid is: %d and its execution time in milliseconds is: %lf\n",(int)getpid(),(int)getppid(),(((double)clock()-t2)/CLOCKS_PER_SEC*1000));

        }
        else {
            wait(NULL);
            printf("Parent pid is: %d and its parent pid is: %d and its execution time in milliseconds is: %lf\n",(int)getpid(),(int)getppid(),(((double)clock()-t2)/CLOCKS_PER_SEC*1000));
        }
    }
    return EXIT_SUCCESS;
}
