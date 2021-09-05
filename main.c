#include<stdio.h>
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
        printf("\n2.Assign doctor");
        printf("\n3.Assign room");
        printf("\n4.patient history");
        printf("\n5.number of in-patient ");
        printf("\n6.Details of in-patients");
        printf("\n7.Details of out-patients");
        printf("\n8.doctor wise patient list");        
        printf("\nEnter the option:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                register_patient();
                break;

            case 2:
                printf("\nSelect doctor to assign to patient: ");
                printf("\n1.Dr. Kumar");
                printf("\n2.Dr. Singh");
                printf("\n3.Dr. Aggarwal");
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

            case 3:
                printf("\nEnter id of patient to assign room=");
                scanf("%d",&n);
                printf("Enter room number");
                scanf("%d",&num);
                assign_room(n,num);
                break;

            case 4:
            
                break;
            
            case 5:
                break;
            
            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            default:
                printf("\nWrong option selected");
        }
        printf("\nEnter y/Y to continue..");
        scanf(" %c",&ch);
    } while (ch=='Y' || ch=='y');    
    return 0;
}