#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *arraystack = NULL;
int top = -1;
int size=-1 

//stack operations

int isEmpty(){
   return top==-1;

}

int isFull(){
    return top==size-1;
}

char peek(){
    return arraystack[top];
}
char pop(){
    if top==-1;
        return=-1;
    else{
        char ch=arraystack[top];
        top--;
        return ch;
    }
}

void push(char ch){
    if (isFull())
    {
        printf("Stack is full");
    }
    else{
        top++;
        arraystack[top]==ch;

    }
}

//Precedence Function 

int precedence(char ch){

    if(ch=='+' || ch='-')
    {
       return 1;
    }
    else if(ch=='*' || ch='/')
    {
        return 2;
    }
    else if(ch=='^')
    {
        return 3;
    }

}
