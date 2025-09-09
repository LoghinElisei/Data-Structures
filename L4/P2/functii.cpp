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
void permutari(Nod *cap)
{
    Nod *p=cap;
    while(p->next!=cap)
    {
        afisare(p);
        p=p->next;
    }
    afisare(p);
    p=p->next;
}

void inversare(Nod *&cap)
{
    Nod *p;
    Nod *q;
    Nod *r;
    p=cap;
    q=cap->next;

    while(p->next!=cap)
    {
        p=p->next;
    }
 
    cap->next=p;
    while(cap!=p)
    {
        r=q->next;
        q->next=cap;
        cap=q;
        q=r;
    }

}


