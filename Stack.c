#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* top=NULL;

void push(int data){
    struct node* newnode=malloc(sizeof(struct node));
     if (!newnode) {
        printf("Stack Overflow (Memory Allocation Failed)\n");
        return;
    }
    newnode->data=data;
    newnode->next=top;
    top=newnode;
}

void pop(){
    if(top==NULL){
     printf("Stack underflow! Stack is empty.\n");
     return;
    }
    struct node* temp=top;
    top=top->next;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element is %d.\n", top->data);
}

void display(){
    if(top==NULL){
     printf("Stack is empty.\n");
     return;
    }
    struct node* temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    printf("--- Stack Operations using Linked List ---\n");
    push(10);
    push(24);
    push(32);
    push(17);
    
    display();
    printf("\n");

    peek();
    printf("\n");
    pop();
    display();

  return 0;
}