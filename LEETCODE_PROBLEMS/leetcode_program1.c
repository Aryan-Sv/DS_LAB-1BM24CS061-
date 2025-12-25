#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
typedef struct {
    int inStack[MAX];
    int outStack[MAX];
    int topIn;
    int topOut;  
} MyQueue;
MyQueue* myQueueCreate() {
   MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->topIn = -1;
    q->topOut = -1;
    return q;
}
void myQueuePush(MyQueue* obj, int x) {
      obj->inStack[++obj->topIn] = x;
}


int myQueuePop(MyQueue* obj) {
     if (obj->topOut == -1) {
        while (obj->topIn != -1) {
            obj->outStack[++obj->topOut] = obj->inStack[obj->topIn--];
        }
    }
    return obj->outStack[obj->topOut--];
}


int myQueuePeek(MyQueue* obj) {
    if (obj->topOut == -1) {
        while (obj->topIn != -1) {
            obj->outStack[++obj->topOut] = obj->inStack[obj->topIn--];
        }
    }
    return obj->outStack[obj->topOut];
}


bool myQueueEmpty(MyQueue* obj) {
    return obj->topIn == -1 && obj->topOut == -1;
}


void myQueueFree(MyQueue* obj) {
    free(obj);
}
