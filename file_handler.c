#include<stdio.h>
#include"globals.h"

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
        printf("contents to file written successfully !\n");
    else 
        printf("error writing file !\n");
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