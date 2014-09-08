//
//  LinkedList.c
//  LinkedList
//
//  Created by Dinesh Appavoo on 9/3/14.
//  Copyright (c) 2014 Dinesh Appavoo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE *file_ptr;
bool eofFlag;
struct cell* root=NULL;


struct cell{
    int data;
    struct cell* next;
};

struct cell* createlist();
int member(int, struct cell*);
struct cell* delete(int, struct cell*);
int last(struct cell*);
struct cell* append(struct cell*, struct cell*);
struct cell* reverse(struct cell*);
void display(struct cell*);


int main()
{
    struct cell* head=NULL;
    file_ptr=fopen("/Users/Dany/Documents/C_WORKSPACE/LinkedList/input.txt", "r");
    if(file_ptr==NULL)
    {
        printf("Error opening the file\n");
        exit(EXIT_FAILURE);
    }
    struct cell* previous=NULL;
    struct cell* root=NULL;
    eofFlag=true;
    while (eofFlag) {
       root=createlist();
        
        if (eofFlag) {
        printf("\n\nOriginal Linked List : ");
        display(root);
        printf("Reversed List : ");
        root = reverse(root);
        display(root);
        root = reverse(root);
        printf("After deletion of Node 5 : ");
        display(delete(5, root));
        printf("Append with previous List : ");
        display(append(root, previous));
        printf("Check Member of Function for Node 6 : ");
        printf("%d",member(6, root));
        printf(" (1- Data available and 0 -Data Not Available) \n");
        printf("Last Node of the List : ");
        printf("%d\n\n",last(root));
        previous=root;
    }
    }
    fclose(file_ptr);
    return 0;
    
}
struct cell* createlist()
{
    int cellValue;
    struct cell* head=NULL;
    struct cell* temp=NULL;
    while(fscanf(file_ptr,"%d", &cellValue)!=EOF){
        //printf("%d\n",cellValue);
        if(head==NULL)
        {
        head=(struct cell*) malloc(sizeof(struct cell));
        head->data=cellValue;
        head->next=NULL;
        }else{
            if(cellValue==-1)
            {
                return head;
            }else{
            struct cell* newNode=(struct cell*) malloc(sizeof(struct cell));
            newNode->data=cellValue;
            newNode->next=NULL;
            temp=head;
            while (temp->next!=NULL) {
                temp=temp->next;
            }
            temp->next=newNode;
        }
        }
    }
    eofFlag=false;
    return NULL;
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
    struct cell* temp=p;
    while (temp!=NULL) {
        if(temp->data==n)
        {
            if (temp->next!=NULL) {
                temp->data=temp->next->data;
                temp->next=temp->next->next;
                return p;
            }else
            {
                temp=NULL;
                return p;
            }
        }
        temp=temp->next;
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
    struct cell* temp=p;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=q;
    return p;
}

struct cell* reverse(struct cell* p)
{
	if (p==NULL) {
		return NULL;
	}
    
	struct cell* rev=NULL;
	struct cell* temp=NULL;
	temp=p;
	while (p!=NULL) {
		p=p->next;
		temp->next=rev;
		rev=temp;
		temp=p;
        
	}
    p=rev;
	return rev;
}
void display(struct cell* p)
{
    if(p==NULL)
        return;
    printf("[");
    while (p->next!=NULL) {
        printf("%d",p->data);
        p=p->next;
        printf(",");
    }
    printf("%d",p->data);
    printf("]\n");
}










