#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Proccess
{
    int arrival_time,burst_time,id,total_burst_time;
};

/*
* compare funcrtion to compare two proccesses
* it returns 1 if the first proccess is smaller than the second one
* it returns -1 if the second proccess is smaller than the first one
* it returns 0 if they are eual
* in this problem we have to sort proccesses according to arrive time, and then according to id, and we do not care about burst time
*/
int compare(struct Proccess x,struct Proccess y)
{
    if (x.arrival_time<y.arrival_time)return 1;
    if (x.arrival_time>y.arrival_time)return -1;
    if (x.id<y.id)return 1;
    if (x.id>y.id)return -1;
    return 0;
}

void merge(struct Proccess* arr, int l, int m, int r)
{
    int i,j,k;
    int n1= m-l+1,n2=r-m;
    struct Proccess* L=malloc(n1*sizeof(struct Proccess));
    struct Proccess* R=malloc(n2*sizeof(struct Proccess));
    for (i = 0; i < n1; i++){
        L[i].arrival_time = arr[l + i].arrival_time;
        L[i].burst_time = arr[l + i].burst_time;
        L[i].id = arr[l + i].id;
    }

    for (j = 0; j < n2; j++){
        R[j].arrival_time = arr[m + 1 + j].arrival_time;
        R[j].burst_time = arr[m + 1 + j].burst_time;
        R[j].id = arr[m + 1 + j].id;
    }

    i = 0,j = 0,k = l;
    while (i < n1 && j < n2)
    {
        if (compare(L[i], R[j])>=0){
            arr[k].arrival_time = L[i].arrival_time;
            arr[k].burst_time = L[i].burst_time;
            arr[k].id = L[i].id;
            i++;
        }
        else {
            arr[k].arrival_time = R[j].arrival_time;
            arr[k].burst_time = R[j].burst_time;
            arr[k].id = R[j].id;
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k].arrival_time = L[i].arrival_time;
        arr[k].burst_time = L[i].burst_time;
        arr[k].id = L[i].id;
        i++;
        k++;
    }

    while (j < n2){
        arr[k].arrival_time = R[j].arrival_time;
        arr[k].burst_time = R[j].burst_time;
        arr[k].id = R[j].id;
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(struct Proccess* arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int min(int x,int y){
    if (x<y)return x;
    return y;
}

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}


void enqueue(struct Queue* queue, int item){
    queue->rear = (queue->rear + 1)% queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

void dequeue(struct Queue* queue)
{
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
}

int front(struct Queue* queue)
{
    return queue->array[queue->front];
}


int main()
{
    int n,quantum;
    fscanf(stdin,"%d %d",&n,&quantum);
    struct Proccess* ps=malloc(n*sizeof(struct Proccess));
    int* completion_time=malloc(n*sizeof(int));
    int* turn_around_time=malloc(n*sizeof(int));
    int* waiting_time=malloc(n*sizeof(int));
    int* vis=malloc(n*sizeof(int));
    double average_turn_around_time=0;
    double average_wait_time=0;
    for (int i=0; i<n; i++)
    {
        int arrival_time,burst_time;
        fscanf(stdin,"%d %d",&arrival_time,&burst_time);
        ps[i].arrival_time=arrival_time;
        ps[i].burst_time=burst_time;
        ps[i].total_burst_time=burst_time;
        ps[i].id=i;
        vis[i]=0;
        waiting_time[i]=0;
        turn_around_time[i]=0;
    }
    mergeSort(ps,0,n-1);
    int proccess_cnt=0,spent_time=0,sum=0;
    struct Queue* queue = createQueue(n);
    while (proccess_cnt<n){
        if (queue->size==0){
            int mn=(int)1e9;
            for (int i=0;i<n;i++){
                if (vis[i]==0&&ps[i].arrival_time<=spent_time){
                    mn=min(mn,ps[i].arrival_time);
                }
            }
            if (mn==(int)1e9){
                spent_time++;
                continue;
            }
            else {
                for (int i=0;i<n;i++){
                    if (vis[i]==0&&ps[i].arrival_time==mn){
                        enqueue(queue,i);
                        vis[i]=1;
                    }
                }
            }
        }
        int st=0;
        int i=front(queue);
        st=min(quantum,ps[i].burst_time);
        spent_time+=st;
        if (ps[i].burst_time>0&&ps[i].burst_time<=quantum){
            proccess_cnt++;
            completion_time[ps[i].id]=spent_time;
            turn_around_time[ps[i].id]=completion_time[ps[i].id]-ps[i].arrival_time;
            waiting_time[ps[i].id]=turn_around_time[ps[i].id]-ps[i].total_burst_time;
            dequeue(queue);
        }
        else {
            dequeue(queue);
            for (int j=i+1;j<n;j++){
                if (vis[j]==0&&ps[j].arrival_time<spent_time){
                    enqueue(queue,j);
                    vis[j]=1;
                }
            }
            enqueue(queue,i);
        }
        ps[i].burst_time-=st;
    }
    for (int i=0;i<n;i++){
        fprintf(stdout,"Proccess #%d completion time is: %d , the turn around time is: %d , and the waiting time is: %d\n",i,completion_time[i],turn_around_time[i],waiting_time[i]);
        average_turn_around_time += turn_around_time[i];
        average_wait_time += waiting_time[i];
    }
    average_turn_around_time/=((double)n);
    average_wait_time/=((double)n);
    fprintf(stdout,"The average turn around time is: %lf , and the average waiting time is: %lf\n",average_turn_around_time,average_wait_time);
}
