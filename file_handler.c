#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include"globals.h"

void create_dir(char dir[])
{
    int check = mkdir(dir,0777);
    // check if directory is created or not
    if (!check)
        printf("Directory created\n");
}

void append_to_file(char file_path[],struct Patient *ptr)
{ 
    // open file for appending
    FILE *fout=fopen(file_path, "a");
    if (fout == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return;
    }
    fwrite(ptr,sizeof(struct Patient),1,fout);
    if(fwrite != 0) 
        printf("\nContents to file written successfully !\n");
    else 
        printf("\nError writing file !\n");
    // close file
    fclose(fout);
}

void read_from_file(char file_path[])
{
    struct Patient p;
    //open file for reading
    FILE *fin=fopen(file_path, "r");
    if (fin == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return;
    }

    // read file contents till end of file
    while(fread(&p, sizeof(struct Patient), 1, fin))
        show_patient_details(&p);
  
    // close file
    fclose(fin);
}