//
//  LinkedListRecursive.c
//  LinkedListRecursive
//
//  Created by Dinesh Appavoo on 10/3/14.
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
struct cell* lastnode(struct cell*);
struct cell* append(struct cell*, struct cell*);
struct cell* reverse(struct cell*);
void display(struct cell*);
void displayNode(struct cell*, bool);
struct cell* createlinkedlist(struct cell*);

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
    printf("\n\n====================================================================");
    printf("\n                   LINKED LIST RECURSIVE METHOD                ");
    printf("\n====================================================================");
    while (eofFlag) {
       root=createlist();
        
        if (eofFlag) {
       
        printf("\nOriginal Linked List :                       ");
        display(root);
        printf("\nReversed List :                              ");
        root = reverse(root);
        display(root);
        root = reverse(root);
        printf("\nAfter deletion of Node 5 from original list: ");
        display(delete(5, root));
        printf("\nAppend with previous List :                  ");
        display(append(root, previous));
        printf("\nCheck Member of Function for Node 6 :        ");
        printf("%d",member(6, root));
        printf(" (1- Data available and 0 -Data Not Available) \n");
        printf("\nLast Node of the List :                      ");
        printf("%d\n\n",last(root));
        previous=root;
    }
    }
    fclose(file_ptr);
    return 0;
    
}

struct cell* createlist()
{
    return createlinkedlist(NULL);

}
struct cell* createlinkedlist(struct cell* head)
{
    int cellValue;
    if(fscanf(file_ptr,"%d", &cellValue)==EOF)
    {
        eofFlag=false;
    	return NULL;
    }

    if(head==NULL)
        {
        head=(struct cell*) malloc(sizeof(struct cell));
        head->data=cellValue;
        head->next=NULL;
        root=head;
        return createlinkedlist(head);
        }else{
            if(cellValue==-1)
            {
              return root;
            }else{
            struct cell* newNode=(struct cell*) malloc(sizeof(struct cell));
            newNode->data=cellValue;
            newNode->next=NULL;

            lastnode(head)->next=newNode;
            return createlinkedlist(head);
            }
        }
}
int member(int n, struct cell* p)
{
    if(p==NULL)
    	return 0;
    if(p->data==n)
    	return 1;
    return member(n,p->next);
}
struct cell*  delete(int n, struct cell* p)
{
    if(p==NULL)
    	return root;
    if(p->data==n)
    {
       if (p->next!=NULL) {
           p->data=p->next->data;
           p->next=p->next->next;
           return root;
         }else
            {
                p=NULL;
                return root;
            }
      }
    return delete(n, p->next);
}

int last(struct cell* p)
{
    if(p==NULL)
        return -1;
    if(p->next==NULL) {
        return p->data;
    	}
    return last(p->next);
}

struct cell* lastnode(struct cell* p)
{
    if(p==NULL)
        return NULL;
    if(p->next==NULL) {
        return p;
    	}
    return lastnode(p->next);
}


struct cell* append(struct cell* p, struct cell* q)
{
    if(p==NULL&&q==NULL)
        return NULL;
    else if (p==NULL||q==NULL)
        return (p==NULL?q:p);
    if(p->next==NULL)
	{
		p->next=q;
		return p;
    }
    return append(p->next,q);

}

struct cell* reverse(struct cell* p)
{
    if(p==NULL)
	{
		return NULL;
	}
	if (p->next==NULL) {
		root=p;
		return p;
	}
	 reverse(p->next);
	 p->next->next=p;
	 p->next=NULL;
	 return root;
}

void display(struct cell* p)
{
	 if(p!=NULL)
		displayNode(p,true);
}

void displayNode(struct cell* p, bool n)
{
    if(p==NULL)
    {
        printf("]");
        return;
     }
	if(n==true)
	{
    	printf("[");
    	}
    printf("%d",p->data);
	if(p->next!=NULL)
    	printf(",");

    return displayNode(p->next,false);

}










