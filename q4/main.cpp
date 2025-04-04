#include <iostream.h>
#include <conio.h>

// Turbo C++ doesn't fully support namespaces

#define MAX_SIZE 100 // Defining a maximum size for the stack

// Implementing a simple stack using an array
struct Stack
{
    char data[MAX_SIZE];
    int top;
};

void initialize(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return (s->top == -1);
}

int isFull(Stack *s)
{
    return (s->top == MAX_SIZE - 1);
}

void push(Stack *s, char c)
{
    if (!isFull(s))
    {
        s->data[++(s->top)] = c;
    }
    else
    {
        cout << "Stack Overflow!" << endl;
        getch();
        exit(1); // Exit if stack is full
    }
}

char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->data[(s->top)--];
    }
    else
    {
        cout << "Stack Underflow!" << endl;
        getch();
        exit(1);     // Exit if stack is empty
        return '\0'; // Should not reach here, but added to avoid warnings
    }
}

char peek(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->data[s->top];
    }
    else
    {
        return '\0'; // Return null character if stack is empty
    }
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    Stack s;
    initialize(&s);
    int i, j;
    i = j = 0;
    char c;

    while ((c = infix[i++]) != '\0')
    {
        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push(&s, c);
        }
        else if (c == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove the '('
        }
        else
        {
            while (!isEmpty(&s) && precedence(c) <= precedence(peek(&s)))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }

    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
}

void main()
{
    clrscr();
    char infixExpression[100];
    char postfixExpression[100];

    cout << "Enter infix expression: ";
    cin >> infixExpression;

    infixToPostfix(infixExpression, postfixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    getch();
}