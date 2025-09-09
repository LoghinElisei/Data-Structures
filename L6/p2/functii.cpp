#include <iostream>
#include "functii.h"
using namespace std;

void initQueue(Queue &q)
{
    q.tail=q.head=0;
}

int isEmpty(Queue &q)
{
    return (q.tail==0 && q.head==0);
}

void put(Queue &q, int a)
{
    Element *p=new Element;

    if(p==NULL)
    {
        cout<<"Memorie insuficienta \n";
        exit(EXIT_FAILURE);
    }

    p->data=a;
    p->next=0;
    if(isEmpty(q))
    {
        q.tail=p;
        q.head=p;
    }
    else
    {
        q.tail->next=p;
        q.tail=p;
    }
}
int get(Queue &q)
{
    Element *p;
    int a;
    //!1 element
    if(isEmpty(q))
    {
        cout<<"Coada este goala\n";
        exit(EXIT_FAILURE);
    } 

    a=q.head->data;
    p=q.head;
    
    if(q.tail!=q.head)
    {
        q.head=q.head->next;
    }
    else   //am un singur element
    {
        q.tail=0;
        q.head=0;
    }

    delete p;

    return a;
}

int front(Queue &q)
{
    if(isEmpty(q))
    {
        cout<<"Coada este goala\n";
        exit(EXIT_FAILURE);
    }

    return q.head->data; 
}
