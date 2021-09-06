#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"globals.h"

void register_patient()
{
    struct Patient *ptr,p;
    ptr=&p; 
    printf("\nEnter patient name=");
    while ((getchar()) != '\n');
    fgets(ptr->name,30,stdin);
    printf("\nEnter age=");
    scanf("%d",&ptr->age);
    ptr->room_assigned=-1;
    strcpy(ptr->doc_assigned,"None");
    enqueue(ptr);
    printf("\nPatient registered successfully with id=%d",ptr->id);
}

void show_patient_details(struct Patient *ptr)
{
    printf("\n***************");
    printf("\nPatient id= %d",ptr->id);
    printf("\nPatient name= ");
    puts(ptr->name);
    printf("Patient age= %d",ptr->age);
    printf("\nDoctor appointed= ");
    puts(ptr->doc_assigned);
    printf("Patient type= ");
    if(ptr->room_assigned==-1)
        printf("Out-patient");
    else
    {
        printf("In-Patient");
        printf("\nRoom number= %d",ptr->room_assigned);
    }
}

void enqueue(struct Patient *ptr)
{
    if(rear==SIZE)
    {
        printf("\nList Full");
        return;
    }
    int i;
    for(i=rear-1; i>=0 && priority_queue[i].age<ptr->age ;i--)
    {
        priority_queue[i+1]=priority_queue[i];
    }
    priority_queue[i+1]=(*ptr);
    rear++;
}


struct Patient dequeue()
{
    struct Patient p;
    return p;
} 

void show_queue()
{
    int i;
    printf("\nPatient queue:");
    for(i=0;i<rear;i++)
    {
        show_patient_details(&priority_queue[i]);
        printf("\n\n");
    }
}

void assign_doctor(int index)
{
    // int id=priority_list[index];
    // struct Patient *p=
    // strcpy(*(p->doc_assigned),doctors[index]);
    // puts(doctors[index]);
}

void assign_room(int id,int room_num)
{

}
