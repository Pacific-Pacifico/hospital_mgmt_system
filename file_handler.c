#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include"globals.h"

void create_dir(char dir[])
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    int check = mkdir(dir,0777);
    #endif
    #if defined(_WIN32) || defined(_WIN64)
    int check = mkdir(dir);
    #endif
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

int count_records(char file_path[])
{
    struct Patient p;
    int count=0;
    //open file for reading
    FILE *fin=fopen(file_path, "r");
    if (fin == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return -1;
    }

    // read file contents till end of file
    while(fread(&p, sizeof(struct Patient), 1, fin))
        count++;
  
    // close file
    fclose(fin);
    return count;
}

struct Patient search_by_id(char file_path[],unsigned long id)
{
    struct Patient p,q;
    q.id=-1;
    //open file for reading
    FILE *fin=fopen(file_path, "r");
    if (fin == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return q;
    }

    // read file contents till end of file
    while(fread(&p, sizeof(struct Patient), 1, fin))
        if(p.id==id)
            q=p;
  
    // close file
    fclose(fin);
    return q;
}

// int main()
// {
//     struct Patient temp;
//     // temp=search_by_id("./in_patients/6-8-2021.dat",1630993289);
//     temp=search_by_id("./in_patients/6-8-2021.dat",1630993280);

//     if(temp.id==-1)
//         printf("\nNot found");
//     else
//         printf("%lu",temp.id);
//     return 0;
// }