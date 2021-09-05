#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"globals.h"

struct Patient *register_patient()
{
    struct Patient *p;
    p=(struct Patient *)malloc(sizeof(struct Patient));
    printf("\nEnter patient name:");
    while ((getchar()) != '\n');
    fgets(p->name,30,stdin);
    printf("\nEnter age");
    scanf("%d",&(p->age));
    puts(p->name);
    printf("%d",p->age);
    printf("\nPatient registered successfully with id=%d",p->id);
    return p;
}

void assign_doctor(int index)
{
    struct Patient *p=priority_queue[index];
    strcpy(*(p->doc_assigned),doctors[index]);
    puts(doctors[index]);
}

void assign_room(int id,int room_num)
{

}
