#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]){
    int pageFrames;
    if (argc==1){
        printf("Enter the number of pageframes: (or add it as a command line argument)\n");
        scanf("%d",&pageFrames);
    }
    else {
        pageFrames = atoi(argv[1]);
    }
    int *pages = malloc(pageFrames*sizeof(int));
    int *cnt = malloc(pageFrames*sizeof(int));
    for (int i=0;i<pageFrames;i++){
        pages[i]=-1;
        cnt[i]=0;
    }
    freopen("input.txt","r",stdin);
    int request,hit=0,miss=0;
    while (scanf("%d",&request)!=EOF){
        int found=0;
        for (int i=0;i<pageFrames;i++){
            if (pages[i]==request){
                found=1;
                break;
            }
        }
        if (found==1){
            hit++;
        }
        else {
            miss++;
            int placed=0;
            for (int i=0;i<pageFrames;i++){
                if (pages[i]==-1){
                    pages[i]=request;
                    cnt[i]=0;
                    placed=1;
                    break;
                }
            }
            if (placed==0){
                int mnidx=0;
                for (int i=0;i<pageFrames;i++){
                    if (cnt[i]<cnt[mnidx])mnidx=i;
                }
                pages[mnidx]=request;
                cnt[mnidx]=0;
            }
        }
        for (int i=0;i<pageFrames;i++){
            cnt[i]>>=1;
            if (pages[i]==request){
                cnt[i]|=(1<<7);
            }
        }
    }
    printf("Number of hits are: %d, Number of misses are: %d\n",hit,miss);
    float ratio = hit;
    ratio = ratio/miss;
    printf("Hit/Miss ratio: %f\n",ratio);

}
