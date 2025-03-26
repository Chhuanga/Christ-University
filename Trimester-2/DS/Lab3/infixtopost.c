#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack variables
char *arraystack = NULL;
int top = -1;
int size = -1;

// Stack operations
int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == size - 1;
}

char peek() {
    return arraystack[top];
}

char pop() {
    if (isEmpty()) {
        return -1;
    } else {
        char ch = arraystack[top];
        top--;
        return ch;
    }
}

void push(char ch) {
    if (isFull()) {
        printf("Stack is full\n");
    } else {
        top++;
        arraystack[top] = ch;
    }
}

// Precedence function
int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '^') {
        return 3;
    }
    return 0;
}

// Operand checker
int isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

// Infix to postfix conversion
void infixToPostfix(char *infix, char *postfix) {
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop the '(' from the stack
        } else {
            while (!isEmpty() && precedence(infix[i]) <= precedence(peek())) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    // Pop remaining operators
    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[100];
    char postfix[100];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    size = strlen(infix);
    arraystack = (char *)malloc(size * sizeof(char));

    infixToPostfix(infix, postfix);

    printf("The postfix expression is: %s\n", postfix);

    free(arraystack); // Free dynamically allocated memory
    return 0;
}
