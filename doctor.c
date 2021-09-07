#include<stdio.h>
#include<string.h>
#include"globals.h"

void doc_patients_list()
{
    int option,index;
    char doc_file_name[50];
    printf("\nDoctor's patients list");
    printf("\nSelect doctor: ");
    printf("\n1.Dr. Kumar");
    printf("\n2.Dr. Singh");
    printf("\n3.Dr. Aggarwal");
    printf("\nEnter the option:");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            index=0;
            break;

        case 2:
            index=1;
            break;

        case 3:
            index=2;
            break;

        default:
            printf("\nInvalid option selected");    
    }
    strcpy(doc_file_name,"./doctors/");
    strcat(doc_file_name,doctors[index]);
    strcat(doc_file_name,".dat");
    read_from_file(doc_file_name);
}