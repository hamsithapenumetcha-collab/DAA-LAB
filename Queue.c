#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* front=NULL;
struct node* rear=NULL;

void enqueue(int data){
    struct node* newnode=malloc(sizeof(struct node));
    if (!newnode) {
        printf("Queue Overflow (Memory Allocation Failed)\n");
        return;
    }
    newnode->data=data;
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }else{
    rear->next=newnode;
    rear=newnode;
    }
}

void dequeue(){
    if (front == NULL) {
        printf("Queue Underflow!Queue is empty.\n");
        return;
    }
   struct node* temp=front;
   printf("Dequeued %d from the queue.\n", front->data);
   front=front->next;
    if(front==NULL){
        rear=NULL;
    }
   free(temp);
}

void display(){
     if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct node*temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    printf("--- Queue Operations using Linked List ---\n");
    enqueue(23);
    enqueue(45);
    enqueue(60);
    enqueue(78);
    display();
    printf("\n");
    dequeue();
    display();
    printf("\n");
    dequeue();
    display();

    return 0;
}