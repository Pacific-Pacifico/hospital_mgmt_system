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
    do
    {
        printf("\nSelect the desired option:");
        printf("\n1.register patient");
        printf("\n2.show patient queue");
        printf("\n3.Assign doctor");
        printf("\n4.Assign room");
        printf("\n5.remove patient from queue");
        printf("\n6.patient history");
        printf("\n7.number of in-patient ");
        printf("\n8.Details of in-patients");
        printf("\n9.Details of out-patients");
        printf("\n10.doctor wise patient list");
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
                ptr=peek();
                if(ptr!=NULL)
                {
                    id=ptr->id;            
                    dequeue();
                    printf("\nPatient with id=%lu successfully removed from queue",id);
                }
                break;
            
            case 6:
                break;
            
            case 7:
                break;

            case 8:
                break;

            case 9:
                break;

            case 10:
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