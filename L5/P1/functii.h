#ifndef DOC_H
#define DOC_H
#define DIM_MAX 1024

struct stack{
    int sp;
    int vect[DIM_MAX];
};

int isEmpty(const stack &s); 
int top(const stack &s);
int pop(stack &s);
void push(stack &s,int a);
void initStack(stack &s);
#endif