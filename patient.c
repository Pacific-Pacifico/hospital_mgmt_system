#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
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
    ptr->id=(long)time(NULL);  //Assign id
    enqueue(ptr);
    printf("\nPatient registered successfully with id=%ld",ptr->id);
}

void show_patient_details(struct Patient *ptr)
{
    printf("\n***************");
    printf("\nPatient id= %lu",ptr->id);
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

int is_empty()
{
    if(front==-1)
        return 1;
    else
        return 0;
}

int is_full()
{
    if(rear==SIZE-1)
        return 1;
    else
        return 0;
}

void enqueue(struct Patient *ptr)
{
    if(is_full())
    {
        printf("\nList Full");
        return;
    }
    if(front==-1)    // when first patient registered
        front=0;
    int i;
    for(i=rear-1; i>=0 && priority_queue[i].age<ptr->age ;i--)
    {
        priority_queue[i+1]=priority_queue[i];
    }
    priority_queue[i+1]=(*ptr);
    rear++;
}

void dequeue()
{
    if(is_empty())
    {
        printf("\nEmpty List");
        return;
    }
    int i;
    for(i=1;i<=rear;i++)
    {
        priority_queue[i-1]=priority_queue[i];
    }
    rear--;
}

struct Patient *peek()
{
    if(is_empty())
    {
        printf("\nEmpty List");
        return NULL;
    }
    return &priority_queue[front];
}

void show_queue()
{
    if(is_empty())
    {
        printf("\nEmpty List");
        return;        
    }
    int i;
    printf("\nPatient queue:");
    for(i=front;i<rear;i++)
    {
        show_patient_details(&priority_queue[i]);
        printf("\n\n");
    }
}

void assign_doctor(int index)
{
    struct Patient *ptr;
    unsigned long id;
    ptr=peek();
    id=ptr->id;
    strcpy(ptr->doc_assigned,doctors[index]);
    show_patient_details(ptr);
}

void assign_room(int id,int room_num)
{

}
