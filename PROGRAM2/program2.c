#include<stdio.h>
#include<string.h>
#define size 5
int top = -1;
char stack[size];

void pushchar(char ch){
    if(top==(size-1)){
        printf("The stack is full\n");
    }
    else{
        top++;
        stack[top] = ch;
    }
}
char popchar(){
    if(top==-1)
        printf("The stack is empty\n");
    else{
        return stack[top--];
    }
}

void main(){
    int i;
    char str[20];
    printf("Enter the string\n");
    gets(str);
    for(i=0;i< strlen(str);i++){
        pushchar(str[i]);
    }
    for(i=0;i< size; i++){
        str[i]=popchar();
    }
    printf("The reversed string is:\n");
    puts(str);
}
