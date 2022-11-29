#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
int pressed[256];
int main() {
    int fd=open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    FILE *out=fopen("./ex3.txt","w");
    struct input_event evt;
    while (1) {
         read(fd,&evt,sizeof(evt));
         if (evt.value==1){
		pressed[evt.code]=1;
   	 }
  	 else if (evt.value==0) {
		pressed[evt.code]=0;
    	 }
   	 int numOfKeysPressed=0;
   	 for (int i=0;i<256;i++){
	 	numOfKeysPressed+=pressed[i];
    	 }
         if (pressed[18]==1 && pressed[25]==1 && numOfKeysPressed==2){
		printf("I passed the Exam!\n");
		fprintf(out,"I passed the Exam!\n");
         }
         if (pressed[46]==1 && pressed[30] && pressed[25] && numOfKeysPressed==3){
		printf("Get some cappuccino!\n");
		fprintf(out,"Get some cappuccino!\n");
   	 }
         if (pressed[16]==1 && pressed[17] && pressed[18] && numOfKeysPressed==3){
		printf("qwerty\n");
		fprintf(out,"qwerty\n");
         }// qwe
	 fflush(out);
    }
    fclose(out);
    return EXIT_SUCCESS;
}
