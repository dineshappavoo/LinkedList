//
//  LinkedList.c
//  LinkedList
//
//  Created by Dinesh Appavoo on 9/3/14.
//  Copyright (c) 2014 Dinesh Appavoo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct cell{
    int data;
    struct cell* next;
};

void readInputFromFile();
void createlist(struct cell*);
int member(int, struct cell*);
struct cell* delete(int, struct cell*);
int last(struct cell*);
struct cell* append(struct cell*, struct cell*);
struct cell* reverse(struct cell*);
void display(struct cell*);


int main()
{
    
    
    
}
void readInputFromFile()
{
    FILE *file_ptr;
    int cellValue;
    char fileName[25];
    
    printf("Enter the file name");
    gets(fileName);
    
    file_ptr=fopen(fileName, "r");
    
    if(file_ptr==NULL)
    {
        printf("Error opening the file\n");
        exit(EXIT_FAILURE);
    }
               
    while((fscanf(file_ptr,"%d", &cellValue) == 1 )){
                   
                   
        }
}
void createlist(struct cell* p)
{
    struct cell* head;
    
    head=(struct cell*) malloc(sizeof(struct cell));
    head->data=5;
    head->next=NULL;
    
}
int member(int n, struct cell* p)
{
    while (p!=NULL) {
        if (p->data==n) {
            return 1;
        }
        p=p->next;
    }
    return 0;
}
struct cell*  delete(int n, struct cell* p)
{
    while (p!=NULL) {
        if(p->data==n)
        {
            if (p->next!=NULL) {
                p->data=p->next->data;
                p->next=p->next->next;
            }else
            {
                p=NULL;
            }
            
        }
    }
    return p;
}
int last(struct cell* p)
{
    while (p!=NULL) {
        if (p->next==NULL) {
            return p->data;
        }
    }
    return -1;
}
struct cell* append(struct cell* p, struct cell* q)
{
    if(p==NULL&&q==NULL)
        return NULL;
    else if (p==NULL||q==NULL)
        return (p==NULL?q:p);
    
    while (p->next!=NULL) {
        p=p->next;
    }
    p->next=q;
    return p;
}






