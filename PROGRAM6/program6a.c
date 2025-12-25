#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* create_node(int value) {
    node *temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        exit(1);
    }
    temp->data = value;
    temp->next = NULL;
    return temp;
}

node* insert_beg(node *head, int value) {
    node *newNode = create_node(value);
    newNode->next = head;
    return newNode;
}

void display(node *head) {
    node *current = head;
    if (current == NULL) {
        printf("Empty\n");
        return;
    }
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

node* reverse_list(node *head) {
    node *prev = NULL;
    node *current = head;
    node *next_node = NULL;

    while (current != NULL) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    return prev;
}

node* sort_list(node *head) {
    int swapped;
    node *current;
    node *lptr = NULL;

    if (head == NULL) return head;

    do {
        swapped = 0;
        current = head;

        while (current->next != lptr) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        lptr = current;
    } while (swapped);

    return head;
}

node* concat_lists(node *head1, node *head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;

    return head1;
}

void free_list(node *head) {
    node *current = head;
    node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    node *head1 = NULL;
    node *head2 = NULL;
    node *concat_head = NULL;
    int m, n, val, i;
    printf("Enter no. of nodes for List 1: ");
    if (scanf("%d", &m) != 1 || m < 0) {
        return 1;
    }

    printf("Enter the %d integer values for List 1: \n", m);
    for (i = 0; i < m; i++) {
        if (scanf("%d", &val) == 1) {
            head1 = insert_beg(head1, val);
        } else {
            break;
        }
    }
    printf("List 1 is: ");
    display(head1);

    printf("\nEnter no. of nodes for List 2: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        free_list(head1);
        return 1;
    }
    printf("Enter the %d integer values for List 2: \n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &val) == 1) {
            head2 = insert_beg(head2, val);
        } else {
            break;
        }
    }
    printf("List 2 is: ");
    display(head2);
    printf("Operations\n");
    head1 = reverse_list(head1);
    printf("Reversed List 1 is: ");
    display(head1);
    head2 = reverse_list(head2);
    printf("Reversed List 2 is: ");
    display(head2);
    head1 = sort_list(head1);
    head2 = sort_list(head2);
    printf("Sorted List 1 is: ");
    display(head1);
    printf("Sorted List 2 is: ");
    display(head2);
    concat_head = concat_lists(head1, head2);
    printf("\nConcatenated List is: ");
    display(concat_head);
    free_list(concat_head);
    return 0;
}
