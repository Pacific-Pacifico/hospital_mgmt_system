#include<stdio.h>
#include<stdlib.h>
#include"globals.h"

int main()
{
    struct Patient p1;
    int option,n,num;
    char ch;
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
        printf("\n5.patient history");
        printf("\n6.number of in-patient ");
        printf("\n7.Details of in-patients");
        printf("\n8.Details of out-patients");
        printf("\n9.doctor wise patient list");
        printf("\n10.Exit");        
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
                printf("\nSelect doctor to assign to patient: ");
                printf("\n1.Dr. Kumar");
                printf("\n2.Dr. Singh");
                printf("\n3.Dr. Aggarwal");
                printf("\nEnter the option:");
                scanf("%d",&option);
                switch(option)
                {
                    case 1:
                        n=0;
                        break;

                    case 2:
                        n=1;
                        break;

                    case 3:
                        n=2;
                        break;

                    default:
                        printf("\nInvalid option selected");    
                }
                assign_doctor(n);
                break;

            case 4:
                printf("\nEnter id of patient to assign room=");
                scanf("%d",&n);
                printf("Enter room number");
                scanf("%d",&num);
                assign_room(n,num);
                break;

            case 5:

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
                exit(1);

            default:
                printf("\nWrong option selected");
        }
        printf("\nEnter y/Y and press enter to continue..");
        scanf(" %c",&ch);
    } while (ch=='Y' || ch=='y');    
    return 0;
}