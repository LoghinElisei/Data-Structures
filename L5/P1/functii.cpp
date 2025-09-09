#include <iostream>
#include "functii.h"
using namespace std;

void initStack(stack &s)
{
    s.sp=-1;
}

void push(stack &s,int a)
{
    if(s.sp<DIM_MAX-1)
    {
        s.sp++;
        s.vect[s.sp]=a;
    }
    else
    {
        cout<<"Stiva este plina \n";
    }
}

int pop(stack &s)
{
    if(s.sp!=-1)
    {
       return s.vect[s.sp--]; 
    }
    else
    {
        cout<<"Stiva este goala\n";
        exit(EXIT_FAILURE);
    }
}

int top(const stack &s)
{
    if(s.sp!=-1)
    {
        return s.vect[s.sp];
    }
    else
    {
        cout<<"Stiva este goala \n";
        exit(EXIT_FAILURE);
    }
}

int isEmpty(const stack &s)
{
    return s.sp==-1;
}
