#include<stdio.h>
#include<stdlib.h>


struct Directory;
struct File;

struct File{
    short int id;
    char name[64];
    int size;
    char data[1024];
    struct Directory * directory;// The parent directory
};

struct Directory{
    int nf;
    int nd;
    char path[2048];
    struct File* files[256];
    struct Directory* directories[8];
};

typedef struct Directory Directory;
typedef struct File File;


// Operations on files
void add_to_file(File *file, const char * content);
void append_to_file(File *file, const char * content);
void pwd_file(File * file);


// Operations on directories
void add_file(File* file, Directory *dir);
void add_dir(Directory *dir1, Directory *dir2); // given to you

// Helper functions
void show_dir(Directory *dir);
void show_file(File *file);
void show_file_detailed(File *file);

int numberOfFiles;
int main(){

    char content1[] = "int printf(const char * format, ...);";
    char content2[] = "int main(){printf('Hello World');}";
    char content3[] = "//This is a comment in C language";
    char content4[] = "Bourne Again Shell!";



    Directory home, bin, root;

    strcpy(root.path,"/");
    root.nd=0;
    root.nf=0;

    strcpy(home.path,"/home");
    home.nd=0;
    home.nf=0;

    strcpy(bin.path,"/bin");
    bin.nd=0;
    bin.nf=0;

    // Example: the path of the folder home is /home

    // Add subdirectories
    add_dir(&home, &root);
    add_dir(&bin, &root);

    File bash, ex31, ex32;

    strcpy(bash.name,"bash");
    bash.id=numberOfFiles++;
    strcpy(bash.data,"");
    bash.size=0;

    strcpy(ex31.name,"ex3_1.c");
    ex31.id=numberOfFiles++;
    strcpy(ex31.data,"");
    ex31.size=0;

    strcpy(ex32.name,"ex3_2.c");
    ex32.id=numberOfFiles++;
    strcpy(ex32.data,"");
    ex32.size=0;


    add_file(&bash,&bin);
    add_file(&ex31,&home);
    add_file(&ex32,&home);

    add_to_file(&bash,content4);
    add_to_file(&ex31,content1);
    add_to_file(&ex32,content3);


    append_to_file(&ex31,content2);

    show_dir(&root);
    show_file_detailed(&bash);
    show_file_detailed(&ex31);
    show_file_detailed(&ex32);

   pwd_file(&bash);
   pwd_file(&ex31);
   pwd_file(&ex32);

   return EXIT_SUCCESS;
}

// Helper functions

// Displays the content of the Directory dir
void show_dir(Directory *dir){
    printf("\nDIRECTORY\n");
    printf(" path: %s\n", dir->path);
    printf(" files:\n");
    printf("    [ ");
    for (int i = 0; i < dir->nf; i++){
        show_file(dir->files[i]);
    }
    printf("]\n");
    printf(" directories:\n");
    printf("    { ");

    for (int i = 0; i < dir->nd; i++){
        show_dir(dir->directories[i]);
    }
    printf("}\n");
}

// Prints the name of the File file
void show_file(File *file){
    printf("%s ", file->name);
}

// Shows details of the File file
void show_file_detailed(File *file){
    printf("\nFILE\n");
    printf(" id: %d\n", file->id);
    printf(" name: %s\n", file->name);
    printf(" size: %lu\n", file->size);
    printf(" data:\n");
    printf("    [ %s ]\n", file->data);
}



// Implementation: Operations on files

// Adds the content to the File file
void add_to_file(File *file, const char * content) {

	strcpy(file->data,content);
    file->size=strlen(content);

}

// Appends the content to the File file
void append_to_file(File *file, const char * content) {
	strcat(file->data,content);
	file->size+=strlen(content);

}

// Prints the path of the File file
void pwd_file(File * file) {
	printf("%s/%s\n",file->directory->path,file->name);
	// Example: the path for bash file is /bin/bash

}


// Implementation: Operations on directories
// Adds the File file to the Directory dir
void add_file(File* file, Directory *dir) {
	dir->files[dir->nf]=file;
	file->directory=dir;
	dir->nf++;

}

// Given to you
// Adds the subdirectory dir1 to the directory dir2
void add_dir(Directory *dir1, Directory *dir2){
	if (dir1 && dir2){
		dir2->directories[dir2->nd] = dir1;
		dir2->nd++;
	}
}
