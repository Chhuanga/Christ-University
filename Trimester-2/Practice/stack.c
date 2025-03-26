#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100


typedef struct{
    int id;
    char title[50];
}Book;

Book stack[MAX];
int top = -1;


void push(int id,char title[]){
    if(top == MAX -1 )
    {
        printf("Overflow");
        return;
    }
    top++;
    stack[top].id = id;
    strcpy(stack[top].title , title);

}

Book pop()
{
    if(top == -1)
    {
        printf("Underflow");
    }
    return stack[top--];
}

Book peek()
{
    if(top == -1)
    {
        printf("Underflow");
    }
    return stack[top];
}

int main() {
    push(1, "Book One");
    push(2, "Book Two");
    Book b = pop();
    printf("Popped: %d, %s\n", b.id, b.title);
    b=peek();
    b=pop();
    printf("Top: %d, %s\n", b.id, b.title);
    return 0;
}