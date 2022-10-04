#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>

int main(void){
    int fd;
    char buf;
    char* named_pipe = "/tmp/ex1";
    mkfifo(named_pipe,0777);
    while (1){
        fd = open(named_pipe,O_RDONLY);
        fprintf(stdout,"Received: ");
        while (read(fd,&buf,1)){
            if (buf=='\n'||buf=='\0')break;
            fprintf(stdout,"%c",buf);
        }
        fprintf(stdout,"\n");
        close(fd);
    }
}
