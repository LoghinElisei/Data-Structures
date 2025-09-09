#include <iostream>
#include "functii.h"
using namespace std;

void initQueue(Queue &Q)
{
    Q.head=Q.tail=0;
}


int isEmpty(Queue &Q)
{
    return (Q.head==Q.tail);
}

int NextPos(int pos)
{
    if(pos<DIMMAX-1)
    return pos+1;

    return 0;
}

void put(Queue &Q,int a)
{
    if(Q.head==NextPos(Q.tail))
    {
        cout<<"Buffer plin \n";
        exit(EXIT_FAILURE);
    }
    else
    {
       Q.vect[Q.tail]=a;
       Q.tail=NextPos(Q.tail);
    }
}
int get(Queue &Q)
{
    int a;
    if(!isEmpty(Q))
    {
        a=Q.vect[Q.head];
        Q.head=NextPos(Q.head);
        return a;
    }
    else
    {
        cout<<"Coada este goala\n";
        exit(EXIT_FAILURE);
    }
}

int front(Queue &Q)
{
    int a;
    if(!isEmpty(Q))
    {
        a=Q.vect[Q.head];
        return a;
    }
    else
    {
        cout<<"Coada este goala \n";
        exit(EXIT_FAILURE);
    }
}
