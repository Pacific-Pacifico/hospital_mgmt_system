#include<stdio.h>
#include<stdlib.h>
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
    return p;
}