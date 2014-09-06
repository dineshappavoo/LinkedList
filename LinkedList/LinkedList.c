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

void createlist();
int member(int, struct cell*);
struct cell* delete(int, struct cell*);
int last(struct cell*);
struct cell* append(struct cell*, struct cell*);
struct cell* reverse(struct cell*);
void display(struct cell*);


int main()
{
 
    createlist();
    struct cell* head=NULL;
    printf("%d\n",member(7, head));
    return 0;
    
}
void createlist()
{
    FILE *file_ptr;
    int cellValue;
    //char fileName[25];
    
    //printf("Enter the file name");
    //gets(fileName);
    
    file_ptr=fopen("/Users/Dany/Documents/C_WORKSPACE/LinkedList/input.txt", "r");
    
    if(file_ptr==NULL)
    {
        printf("Error opening the file\n");
        exit(EXIT_FAILURE);
    }
    
    struct cell* head=NULL;

    printf("Test 1\n");

    if(NULL == file_ptr)
        printf("File not available\n");
    while(fscanf(file_ptr,"%d", &cellValue)>0){
        printf("Test 2\n");

        printf("%d\n",cellValue);
        if(head==NULL)
        {
        head=(struct cell*) malloc(sizeof(struct cell));
        head->data=cellValue;
        head->next=NULL;
        }else{
            
            if(cellValue==-1)
            {
                printf("Test");
                printf("%d\n",member(7, head));
                printf("%d\n",last(head));

                head=NULL;
            }else{
            struct cell* newNode=(struct cell*) malloc(sizeof(struct cell));
            newNode->data=cellValue;
            newNode->next=NULL;
            while (head->next!=NULL) {
                head=head->next;
            }
            head->next=newNode;
        }
        }
    }
    fclose(file_ptr);

    
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
    if(p==NULL)
        return -1;
    while (p->next!=NULL) {
        p=p->next;
    }
    return p->data;
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






