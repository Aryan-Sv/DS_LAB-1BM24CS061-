#include <stdio.h>
# define SIZE 3
int item[SIZE];
int front=-1;
int rear=-1;

int Full(){
if((front==rear+1) || (front==0 && rear==SIZE-1)) return 1;
return 0;
}


int Empty(){
if((front==-1)) return 1;
return 0;
}

void deque(){
    int ele;
    if(Empty()) printf("Queue Underflow\n");
    else{
        ele=item[front];
        if(front==rear){
            front=-1;rear=-1;
        }
        else {
            front=(front+1)%SIZE;
        }
        printf("\n Deleted element: %d \n",ele);
    }
}

void enQue(int ele){
    if(Full()) printf("Queue is full\n");
    else {
        if(front==-1 && rear==-1){
            front=0;
        }
        rear=(rear+1)%SIZE;
        item[rear]=ele;
        printf("Element inserted \n");
    }
}

void display(){
    int i;
    if(Empty()) printf("Empty Queue\n");
    else {
        printf("Queue element \n");
        for (i=front;i!=rear;i=(i+1)%SIZE) printf("%d ",item[i]);
        printf("%d \n",item[i]);
    }
}

main(){
    int choice;
    while(1){
        int n;
        printf(" 1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:

                printf("Enter element \n");
                scanf("%d",&n);
                enQue(n);
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid Choice\n");
        }
    }
}
