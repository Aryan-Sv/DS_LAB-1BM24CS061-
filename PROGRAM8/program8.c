#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
};

struct node* insert(struct node* root,int val){
    if(root == NULL) return create(val);
    if(val<root->data)
        root->left = insert(root->left,val);
    else if(val>root->data)
        root->right = insert(root->right,val);
    return root;
};

void inorder_tra(struct node* root){
    if(root!=NULL){
        inorder_tra(root->left);
        printf("%d ",root->data);
        inorder_tra(root->right);
    }
}

void preorder_tra(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder_tra(root->left);
        preorder_tra(root->right);
    }
}

void postorder_tra(struct node* root){
    if(root!=NULL){
        postorder_tra(root->left);
        postorder_tra(root->right);
        printf("%d ",root->data);
    }
}

void display(struct node* root){
    printf("Display in Inorder traversal:\n");
    inorder_tra(root);
    printf("\n");
}

void main(){
    struct node *root = NULL;
    int val,choice;

    do{
        printf("----MENU----\n");
        printf("1. Insert \n2. Traversal \n3. Display \n4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value \n");
                    scanf("%d",&val);
                    root = insert(root,val);
                    break;
            case 2: printf("Inorder traversal\n");
                    inorder_tra(root);
                    printf("\n");
                    printf("Preorder traversal\n");
                    preorder_tra(root);
                    printf("\n");
                    printf("Postorder traversal\n");
                    postorder_tra(root);
                    printf("\n");
                    break;
            case 3: display(root);
                    break;
            case 4: printf("Exiting !!\n");
                    exit(1);
            default: printf("Invalid choice\n");

        }
    }while(choice!=4);
}
