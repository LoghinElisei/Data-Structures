#ifndef DOC_H
#define DOC_H

struct Element{
    char op;
    Element *next;
};
typedef Element *stack;

bool isEmpty(stack s);
char pop(stack &s);
void push(stack &sp,int x);
void initStack(stack &s);
char top(stack s);
void conversie(char infixat[],char polonez[]);
int prioritate(char c);
int evaluare(char polonez[]);

#endif