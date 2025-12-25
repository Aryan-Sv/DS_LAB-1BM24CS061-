#include<stdio.h>
#define max 3
int queue_array[max];
int rear = -1;
int front = -1;
void main(){
    int choice;
    while(1){
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 :insert();
                    break;
            case 2 :delete();
                    break;
            case 3 :display();
                    break;
            case 4 :exit(1);

            default :printf("Invalid choice\n");

        }
    }
}

insert(){
    int add_item;
    if(rear==max-1)
        printf("Queue overflow !\n");
    else{
        if (front==-1)
            front =0;
        printf("Enter the element in queue:\n");
        scanf("%d",&add_item);
        rear+=1;
        queue_array[rear]= add_item;

    }

}

delete(){
    if(front==-1 || front>rear){
        printf("Queue underflow!\n");
        return;
    }
    else{
        printf("Deleted item:%d\n",queue_array[front]);
        front+=1;
    }
}

display(){
    int i;
    if(front==-1)
        printf("Queue is empty!");
    else{
        printf("Queue is\n");
        for(i=front;i<=rear;i++)
            printf("%d",queue_array[i]);
        printf("\n");
    }
}
