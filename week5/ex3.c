#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

int* count;
sem_t sem;

typedef struct prime_counter_request
{
    int start, finish;
} prime_counter_request;


void* prime_counter(void* arg)
{
    prime_counter_request* astruct = (prime_counter_request *) arg;
    int min = astruct->start;
    int max = astruct->finish;
    for(int i = min; i <= max; i++)
    {
        bool prime = true;
        for( int j = 2; j*j <= i; j++ )
        {
            if( i % j == 0 ){
                prime = false;
                break;
            }
        }
        if (i==1)prime=false;
        if( prime )
        {
            sem_wait(&sem);
            (*count)++;
            sem_post(&sem);
        }
    }
    free(arg);
    return (void*)count;
}


int main( int argc, char *argv[] )
{
    int n = atoi(argv[1]), n_threads = atoi(argv[2]);
    int segment_size = n / n_threads;

    pthread_t *threads = malloc(n_threads * sizeof(pthread_t));

    count = malloc(sizeof(int));
    *count = 0;
    sem_init(&sem, 0, 1);

    for (int i = 0; i < n_threads; i++)
    {
        prime_counter_request *request = (prime_counter_request *)malloc( sizeof( prime_counter_request ) );

        request->start = i*segment_size+1;

        int threadMax = i*segment_size+segment_size-1;
        if( i == n_threads-1 )
        {
            threadMax = n;
        }
        request->finish = threadMax;

        pthread_create(&threads[i], NULL, (void*)prime_counter, request );
    }

    for(int i = 0; i < n_threads; i++)
        pthread_join( threads[i], NULL);

    printf( "%d\n", *count);

    free(count);
    free(threads);
    return 0;
}
