#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>

int main ( int argc, char ** argv ) {
    freopen("ex4.txt","w",stdout);
    struct dirent *dp;
    char *dir;
    dir = "tmp";
    DIR *dfd=opendir(dir);
    struct stat st;
    char filename_qfd[1000] ;
    while ((dp = readdir(dfd)) != NULL){
	sprintf( filename_qfd , "%s/%s",dir,dp->d_name) ;
	stat(filename_qfd,&st);
	if (st.st_nlink>=2){
		printf("%s\n",dp->d_name);
	}
    }
    closedir(dfd);
    return 0;
}
