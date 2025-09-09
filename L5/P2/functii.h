#ifndef DOC_H
#define DOC_H

struct Element{
    int val;
    Element *next;
};
typedef Element *stack;

bool isEmpty(stack s);
int pop(stack &s);
void push(stack &sp,int x);
void initStack(stack &s);
int top(stack s);

#endif