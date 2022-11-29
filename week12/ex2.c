#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd=open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    FILE *out=fopen("./ex2.txt","w");
    struct input_event evt;
    while (1) {
        read(fd,&evt,sizeof(evt));
        if (evt.type == EV_KEY&&(evt.value==0||evt.value==1)){
	    if (evt.value==1){
		printf("PRESSED ");
		fprintf(out,"PRESSED ");
	    }
	    else {
		printf("RELEASED ");
		fprintf(out,"RELEASED ");
	    }
            printf("0x%.4x (%d)\n",evt.code,evt.code);
            fprintf(out,"0x%.4x (%d)\n",evt.code,evt.code);
        }
	fflush(out);
    }
    fclose(out);
    return EXIT_SUCCESS;
}

