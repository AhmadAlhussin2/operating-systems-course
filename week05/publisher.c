#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>

int main(int argc,char *argv[]){
    int n=atoi(argv[1]);
    if (n==0||n>3){
        fprintf(stdout,"Usage: sh ex1.h n\n");
        return 0;
    }
    int fd;
    char message[1024];
    char* named_pipe = "/tmp/ex1";
    mkfifo(named_pipe,0777);
    while (1){
        strcpy(message,"");
        fd = open(named_pipe,O_WRONLY);
        fgets(message,1024,stdin);
        for (int i=0;i<n;i++){
            write(fd,message,strlen(message));
        }
        close(fd);
        sleep(1);
    }
}
