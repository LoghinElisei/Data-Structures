#include <iostream>
#include "functii.h"
#include <string.h>
using namespace std;

void initStack(stack &s)
{
    s=NULL;
}

void push(stack &sp,char c)
{
    Element *p=new Element;
    p->op=c;
    p->next=sp;
    sp=p;
}

char pop(stack &s)
{   char a;
    a='\0';
    if(!isEmpty(s))
     {  
        Element *p;
        p=s;
        a=p->op;
        s=s->next;
        delete p;
     }
    return a;
}

bool isEmpty(stack s)
{
    return s==0;
}

char top(stack s)
{
    return s->op;
}

int prioritate(char c)
{
    if(c=='+' || c=='-')
     {
        return 1;
     }
    else
    {
        return 2;
    }
}

void conversie(char infixat[],char polonez[])
{
    int i=0,k=0;
    char a,b;
    stack s;
    initStack(s);
    while (infixat[i])
    {
        if(isdigit(infixat[i]))
        {
            polonez[k]=infixat[i];
            k++;
        }
        else
        {
            if(infixat[i]=='(')
            {
                push(s,infixat[i]);
            }
            else if(infixat[i]==')')
            {
                
                while(!isEmpty(s) && top(s)!='(')
                {
                    polonez[k++]=pop(s);
                }
                pop(s);
            }
            else
            {   
                if(!isEmpty(s))
                {
                    a=top(s);
                    while(prioritate(a)>prioritate(infixat[i]) && top(s)!='(')
                    {

                        polonez[k++]=pop(s);
                    }
                    
                }
                push(s,infixat[i]);
            }
        }
        i++;
    }
    while(!isEmpty(s))
    {
        polonez[k++]=pop(s);
    }
}

int evaluare(char polonez[])
{
    int a,b;
    stack s;
    int i=0;
    initStack(s);
    while(polonez[i])
    {
        if(isdigit(polonez[i]))
        {
            push(s,polonez[i]);
        }
        else
        {
            if(!isEmpty(s))
            {
                a=pop(s)-'0';
                b=pop(s)-'0';
            }
           
           if(polonez[i]=='+')
           {
              push(s,a+b);
           }
           else if(polonez[i]=='-')
           {
             push(s,b-a);
           }
           else if(polonez[i]=='/')
           {
            push(s,b/a);
           }
           else
           {
             push(s,b*a);
           }
        }
        i++;
    }
    if(!isEmpty(s))
        return pop(s);
    else
    {
        cout<<"Stiva goala";
        exit(EXIT_FAILURE);
    }
}