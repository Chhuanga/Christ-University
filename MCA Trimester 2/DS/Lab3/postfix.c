//calculating postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Stack Variables

struct Stack{
    int top;
    int* array;
    unsigned capacity;
};

struct Stack* createStack(unsigned capacity){
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));

    if(!stack)
        return 0;
    
    stack->top=-1;
    stack->capacity=capacity;
    stack->array=(int*)malloc(stack->capacity * sizeof(int));

    if(!stack->array)
        return 0;
    return stack;
    


}