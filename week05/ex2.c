#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

struct Thread
{
    int i;
    char message[256];
};

void *print(void *arg)
{
    struct Thread *thread = (struct Thread *)arg;
    strcpy(thread->message,"Hello from thread ");
    char snum[256];
    sprintf(snum, "%d", thread->i);
    strcat(thread->message,snum);
    printf("%s\n",thread->message);
    return NULL;
}


int main(void)
{
    int n;
    fscanf(stdin,"%d",&n);
    struct Thread *threads = malloc(n * sizeof(pthread_t));
    pthread_t thread[n];
    for(int j=0; j<n; j++)
    {
        threads[j].i = j;
        printf("Thread %d is created\n",j);
        pthread_create(&thread[j], NULL, print, (void *)&threads[j]);
        pthread_join(thread[j], NULL);
        printf("Thread %d exits\n\n",threads[j].i);
    }

}
