#include<stdio.h>
#include<string.h>
#include <dirent.h>
#include"globals.h"

void count_in_patients()
{
    int c,count=0;
    char file_path[100];
    DIR *d;
    struct dirent *dir;
    d = opendir("./in_patients");
    if(d)
    {
        while((dir = readdir(d)) != NULL)
        {
            strcpy(file_path,"./in_patients/");
            strcat(file_path,dir->d_name);
            // printf("\nfile=path%s", file_path);
            c=count_records(file_path);
            if(c!=-1)
                count+=c;
            file_path[0]='\0';
        }
        closedir(d);
    }
    printf("\nTotal number of in_patients= %d",count);
}

void show_in_patients()
{
    char file_name[30];
    int day,month,year;
    printf("\nEnter day(1-31)=");
    scanf("%d",&day);
    printf("\nEnter month(1-12)=");
    scanf("%d",&month);
    printf("\nEnter year(xxxx format)=");
    scanf("%d",&year);
    sprintf(file_name,"./in_patients/%d-%d-%d.dat",day,month,year);
    read_from_file(file_name);
}