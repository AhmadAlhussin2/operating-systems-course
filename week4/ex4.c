#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


int main(){
    char line[1024];
    char* argv[120];
    int argc ;
    char file_path[50];
    while(1){
        printf("> ");
        gets(line,1024, stdin);
        size_t length = strlen(line);
        if (line[length-1] == '\n'){
            line[length-1] = '\0';
        }
        char *token;
        token=strtok(line," ");
        int argc=0;
        while(token!=NULL){
            argv[argc]=token;
            token=strtok(NULL," ");
            argc++;
        }
        argv[argc]=NULL;
        strcpy(file_path,"/bin/");
        strcat(file_path,argv[0]);
        pid_t pid=fork();
        if (pid==0) {
            execvp(file_path,argv);
            exit(EXIT_FAILURE);
        }
        else if (pid > 0) {
            wait(NULL);
        }
    }
}
