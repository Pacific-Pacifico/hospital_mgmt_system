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
    {
        front=rear=0;
    }
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
    if(rear==0)
        front=-1;
}

struct Patient *peek()
{
    if(is_empty())
    {
        printf("\nEmpty patients List");
        return NULL;
    }
    return &priority_queue[front];
}

void show_queue()
{
    if(is_empty())
    {
        printf("\nEmpty patients list");
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

void assign_doctor()
{
    int option,index;
    struct Patient *ptr;
    ptr=peek();
    if(ptr==NULL)
        return;
    show_patient_details(ptr);
    printf("\nSelect doctor to assign to patient: ");
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
    strcpy(ptr->doc_assigned,doctors[index]);
    show_patient_details(ptr);
}

void assign_room()
{
    struct Patient *ptr;
    int room_num;
    ptr=peek();
    if(ptr==NULL)
        return;
    printf("Enter room number to assign to patient= ");
    scanf("%d",&room_num);
    ptr->room_assigned=room_num;
}

void remove_from_queue()
{
    struct Patient *ptr;
    unsigned long id;
    char date[30];   
    char file_path[100];
    char doc_file_name[50];
    ptr=peek();
    if(ptr==NULL)
        return;
    id=ptr->id;
    if(ptr->room_assigned==-1)
    {
        strcpy(file_path,"./out_patients/");
    }
    else
    {
        strcpy(file_path,"./in_patients/"); 
    }
    strcpy(date,convert_timestamp_to_time(id));
    strcat(file_path,date);
    strcat(file_path,".dat");
    printf("\nfile path= %s",file_path);
    append_to_file(file_path,ptr);

    strcpy(doc_file_name,"./doctors/");
    strcat(doc_file_name,ptr->doc_assigned);
    strcat(doc_file_name,".dat");
    append_to_file(doc_file_name,ptr); 

    dequeue();
    printf("\nPatient with id=%lu successfully removed from queue",id);
}