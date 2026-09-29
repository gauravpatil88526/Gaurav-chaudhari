#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
char stack[MAX];
int top = -1;

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check if the character is an operand
int isOperand(char c) {
    return isalpha(c);  // Checks if the character is an alphabet
}

// Function to get the precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to push element to the stack
void push(char c) {
    if (top == (MAX - 1)) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

// Function to pop element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1; // Return an invalid character when underflow occurs
    } else {
        return stack[top--];
    }
}

// Function to get the top element of the stack without removing it
char peek() {
    if (top == -1) {
        return -1;
    }
    return stack[top];
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char current;

    while (infix[i] != '\0') {
        current = infix[i];

        // If the current character is an operand, add it to the postfix expression
        if (isOperand(current)) {
            postfix[j++] = current;
        }
        // If the current character is '(', push it to the stack
        else if (current == '(') {
            push(current);
        }
        // If the current character is ')', pop until '(' is found
        else if (current == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop '('
        }
        // If the current character is an operator
        else if (isOperator(current)) {
            while (top != -1 && precedence(peek()) >= precedence(current)) {
                postfix[j++] = pop();
            }
            push(current);
        }
        i++;
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);  // Read the infix expression

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
