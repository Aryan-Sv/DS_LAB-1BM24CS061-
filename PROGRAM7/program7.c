#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head =NULL;

struct node *create(int val){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
};

void insert_end(int val){
    struct node *newnode = create(val);
    if(head ==NULL) head = newnode;
    else{
        struct node *temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insert_left(int val,int key){
    struct node *newnode = create(val);
    if(head ==NULL) head = newnode;
    else{
        struct node *temp = head;
        while(temp!=NULL && temp->data !=key){
            temp = temp->next;
        }
        if(temp==NULL){
            printf("%d is not found, cannot add a node\n",key);
            free(newnode);
        }
        else{
            newnode->next = temp;
            newnode->prev = temp->prev;
            if(temp->prev !=NULL)
                temp->prev->next = newnode;
            else
                head = newnode;
            temp->prev = newnode;
        }
    }
}

void delete_key(int key){
    if(head==NULL) printf("No nodes are present.\n");
    else{
        struct node *temp =head;
        while(temp!=NULL && temp->data!=key)
            temp=temp->next;
        if(temp==NULL) printf("The key is not found\n");
        else{
            if(temp->prev !=NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;
            if(temp->next!=NULL)
                temp->next->prev = temp->prev;
            free(temp);
        }
    }
}

void display(){
    if(head==NULL)printf("List is empty\n");
    else{
        struct node *temp = head;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL");
        printf("\n");
    }
}

void main(){
    int choice,val,key;
    do{
        printf("****MENU****\n");
        printf("1. Insert end \n2. Insert left of a node \n3. Delete a key \n4. Display \n5. Exit");
        printf("\nEnter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value to insert:\n");
                    scanf("%d",&val);
                    insert_end(val);
                    break;

            case 2: printf("Enter the value to insert:\n");
                    scanf("%d",&val);
                    printf("Enter the key:\n");
                    scanf("%d",&key);
                    insert_left(val,key);
                    break;

            case 3: printf("Enter the key to delete\n");
                    scanf("%d",&key);
                    delete_key(key);
                    break;

            case 4: display();
                    break;

            case 5: exit(1);

            default: printf("Invalid choice,try again\n");
        }
    }while(choice!=5);
}
