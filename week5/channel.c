#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    int pipefds[2];
    char message[1024];
    char buffer[1024];

    while (1){
        pipe(pipefds);
        pid_t pid = fork();
        if(pid == 0)
        {
            fgets(message,1024,stdin);
            if (message[strlen(message)-1]=='\n')message[strlen(message)-1]='\0';
            close(pipefds[0]);
            write(pipefds[1], message, 1024);
            close(pipefds[1]);
            sleep(1);
            exit(EXIT_SUCCESS);
        }

        if(pid > 0)
        {
            wait(NULL);
            close(pipefds[1]);
            read(pipefds[0], buffer, 1024);
            close(pipefds[0]);
            fprintf(stdout,"%s\n", buffer);
        }
    }

    return EXIT_SUCCESS;
}
