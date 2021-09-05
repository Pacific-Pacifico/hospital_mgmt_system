#include<stdio.h>
#include"globals.h"

char *doctors[3]={"Dr. Kumar","Dr. Singh","Dr. Aggarwal"};
int main()
{
    struct Patient p1;
    int option;
    char ch;
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
                assign_doctor();
                break;

            case 3:
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