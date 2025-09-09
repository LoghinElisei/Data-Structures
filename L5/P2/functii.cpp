#include <iostream>
#include "functii.h"
using namespace std;

void initStack(stack &s)
{
    s=NULL;
}

void push(stack &sp,int x)
{
    Element *p=new Element;
    p->val=x;
    p->next=sp;
    sp=p;
}

int pop(stack &s)
{
    int a=0;
    Element *p;
    p=s;
    a=p->val;
    s=s->next;
    delete p;

    return a;
}

bool isEmpty(stack s)
{
    return s==0;
}

int top(stack s)
{
    return s->val;
}