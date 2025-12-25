#include <stdio.h>
#include <stdlib.h>

int top = -1;

int isFull(int size) {
    return top == size - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int stack[], int value, int size) {
    if (isFull(size)) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        stack[++top] = value;
        printf("Item %d pushed to stack.\n", value);
    }
}

void pop(int stack[]) {
    if (isEmpty()) {
        printf("Stack Underflow! No items to pop.\n");
    } else {
        int poppedValue = stack[top];  // Access the current top value
        top--;  // Decrement top after accessing the value
        printf("Item %d popped from stack.\n", poppedValue);
    }
}

void display(int stack[]) {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int size, choice, value;
    printf("Enter stack size: ");
    scanf("%d", &size);

    int stack[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &stack[i]);
        top++;
    }

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &value);
                push(stack, value, size);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

