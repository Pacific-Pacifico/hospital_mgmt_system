#include<stdio.h>
#include"globals.h"

void show_patient_history()
{
    int found;
    unsigned long id;
    printf("\nEnter id of the patient=");
    scanf("%lu",&id);
    found=search_patient("./in_patients",id);
    if(!found)
        found=search_patient("./out_patients",id);
    if(!found)
        printf("\n id=%lu not found!!!",id);
}

