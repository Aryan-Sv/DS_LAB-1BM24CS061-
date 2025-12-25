#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*head=NULL;

struct node* create(int value){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node*));
    temp->data = value;
    temp->next = NULL;
    return temp;
};

void insert_begin(int value){
    struct node* newnode;
    newnode = create(value);
    if(head==NULL)
        head = newnode;
    else{
        struct node* temp;
        temp=head;
        newnode->next = temp;
        head = newnode;
    }
}

void insert_end(int value){
    struct node* newnode;
    newnode = create(value);
    if(head==NULL)
        head = newnode;
    else{
        struct node* temp;
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}

void display(){
    struct node* temp;
    if(head==NULL){
        printf("The list id empty\n");
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}

void main(){
    int value,choice;
    while(1){
        printf("****MENU****\n");
        printf("1.Insert at beginning \n2.Insert at end \n3.Display \n4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the data:\n");
                    scanf("%d",&value);
                    insert_begin(value);
                    break;

            case 2: printf("Enter the data:\n");
                    scanf("%d",&value);
                    insert_end(value);
                    break;

            case 3: display();
                    break;

            case 4: exit(1);
            default: printf("Invalid choice");
        }
    }
}
