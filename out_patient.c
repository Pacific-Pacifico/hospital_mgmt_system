#include<stdio.h>
#include"globals.h"

void show_out_patients()
{
    char file_name[30];
    int day,month,year;
    printf("\nEnter day(1-31)=");
    scanf("%d",&day);
    printf("\nEnter month(1-12)=");
    scanf("%d",&month);
    printf("\nEnter year(xxxx format)=");
    scanf("%d",&year);
    sprintf(file_name,"./out_patients/%d-%d-%d.dat",day,month,year);
    read_from_file(file_name);
}
