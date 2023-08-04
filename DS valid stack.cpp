#include <stdio.h>
#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1; 
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push element %d.\n", value);
        return;
    }

    stack->data[++(stack->top)] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return -1; 
    }

    return stack->data[(stack->top)--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty. Cannot peek.\n");
        return -1; 
    }

    return stack->data[stack->top];
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    pop(&stack);
    printf("Top element after pop: %d\n", peek(&stack));

    push(&stack, 40);
    printf("Top element after push: %d\n", peek(&stack));

    return 0;
}

