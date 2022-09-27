#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


// Calculate the dot product of the vectors u and v from the component [start] till the component [end] exclusively.
int dotprod(int u[], int v[], int start, int end){

	int result = 0;

	for (int i=start; i<end; i++){
		result += u[i] * v[i];
	}

	return result;
}


int main(void){
    FILE *pFile=fopen("temp.txt","w");
    int u[120],v[120];
    for (int i=0;i<120;i++){
        u[i]=rand()%100;
        v[i]=rand()%100;
    }
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        if (fork()==0){
            int tmpU,tmpV;
            fprintf(pFile,"%d\n",dotprod(u,v,i*(120/n),i*(120/n)+(120/n)));
            fclose(pFile);
            return EXIT_SUCCESS;
        }
    }
    for (int i=0;i<n;i++)wait(NULL);
    fclose(pFile);
    pFile=fopen("temp.txt","r");
    int ans=0;
    for (int i=0;i<n;i++){
        int x;
        fscanf(pFile,"%d",&x);
        ans+=x;
    }
    fprintf(stdout,"%d",ans);
    fclose(pFile);
	return EXIT_SUCCESS;

}
