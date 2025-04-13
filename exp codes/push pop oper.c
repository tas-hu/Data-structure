#include <stdio.h>
#include <stdlib.h>

// Define a node in the stack
struct Node {
    int data;
    struct Node* next;
};

// Push operation (insert at beginning)
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Stack overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}

// Pop operation (delete from beginning)
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    printf("Popped %d from the stack.\n", poppedValue);
    return poppedValue;
}

// Display the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (top to bottom): ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

// Main function to demonstrate push and pop
int main() {
    struct Node* stack = NULL; // Stack is initially empty

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(stack);

    pop(&stack);
    pop(&stack);

    display(stack);

    pop(&stack);
    pop(&stack); // Try popping from an empty stack

    return 0;
}
