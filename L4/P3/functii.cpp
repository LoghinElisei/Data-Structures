#include <iostream>
#include "functii.h"
using namespace std;

bool inserare(Nod *&cap,int val)
{
    Nod *p=new Nod;

    if(p==NULL)
    {
        cout<<"Eroare la alocare "<<endl;
        return 0;
    }

    p->val=val;

    if(cap==NULL)
    {
        cap=p;
        cap->next=cap;
    }
    else
    {
       p->next=cap->next;
       cap->next=p;
       cap=p;

    }
  
    return 1;
}

void afisare(Nod *cap)
{
    Nod *p=cap;
    cout<<p->val<<' ';
    while(p->next!=cap)
    {
        p=p->next;
        cout<<p->val<<' ';
        
    }
    cout<<endl;
}

void concatenare(Nod *&cap1,Nod *&cap2)
{
    Nod *p=cap1;
    Nod *q=cap2;
    while(p->next!=cap1)
    {
        p=p->next;
    }

    p->next=cap2;

    while(q->next!=cap2)
    {
        q=q->next;
    }

    q->next=cap1;

}

void interclasare(Nod *cap1,Nod *cap2)
{
    Nod *p1,*q1;
    Nod *p2,*q2;

    p1=cap1;
    p2=cap2;
    q1=p1->next;
    q2=p2->next;

    while(q1!=cap1 && q2!=cap2)
    {
        p1->next=p2;
        p2->next=q1;
        cout<<p1->val<<" - "<<p2->val<<endl;
        p1=q1;
        p2=q2;
        
        q1=q1->next;
        q2=q2->next;
    }
    cout<<q1->val<<endl;

    p1->next=p2;
    p2->next=q1;
}
