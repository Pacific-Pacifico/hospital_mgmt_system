#include<stdio.h>
#include<stdlib.h>
#include"globals.h"

int main()
{
    struct Patient p1,*ptr;
    int option,n,num;
    unsigned long id;
    char ch;
    front=rear=-1;
    doctors[0]="Dr. Kumar";
    doctors[1]="Dr. Singh";
    doctors[2]="Dr. Aggarwal";
    create_dir("./doctors");
    create_dir("./out_patients");
    create_dir("./in_patients");
    do
    {
        clear();
        printf("\nSelect the desired option:");
        printf("\n1.register patient");
        printf("\n2.show patient queue");
        printf("\n3.Assign doctor");
        printf("\n4.Assign room");
        printf("\n5.remove patient from queue");
        printf("\n6.patient history");
        printf("\n7.number of in-patients ");
        printf("\n8.Details of in-patients");
        printf("\n9.Details of out-patients");
        printf("\n10.doctor wise patients list");
        printf("\n11.Exit");        
        printf("\nEnter the option:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                register_patient();
                break;

            case 2:
                show_queue();
                break;

            case 3:
                assign_doctor();
                break;

            case 4:
                assign_room();
                break;

            case 5:
                remove_from_queue();
                break;
            
            case 6:
                show_patient_history();
                break;
            
            case 7:
                count_in_patients();
                break;

            case 8:
                show_in_patients();
                break;

            case 9:
                show_out_patients();
                break;

            case 10:
                doc_patients_list();
                break;

            case 11:
                exit(1);

            default:
                printf("\nWrong option selected");
        }
        printf("\nEnter y/Y and press enter to continue..");
        scanf(" %c",&ch);
    } while (ch=='Y' || ch=='y');    
    return 0;
}

void clear()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
    #endif
    #if defined(_WIN32) || defined(_WIN64)
    system("cls");
    #endif
}