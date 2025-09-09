#include <iostream>
#include "functii.h"
using namespace std;

bool inserare(Nod *&cap,int x)
{
    Nod *p = new Nod;
    if (p == 0) 
    {
        cout << "Eroare la alocare" << endl;
        return false;
    }
   
    p->val=x;
    p->next = 0;
   
    if (cap == 0 || (cap->val>x))
    {
        p->next = cap;
        cap = p;
        return true;
    }

    Nod *q = cap;
    while (q->next && (q->next->val<x) )
    {
        q = q->next;
    }

    p->next = q->next;
    q->next = p;
    return true;

}

void afisare(Nod *cap,int x)
{
    cout<<"Lista "<<x<<" este "<<endl<<">>  ";
    while(cap)
    {
        cout<<cap->val<<' ';
        cap=cap->next;
    }

    cout<<endl;
}

void concatenare(Nod *&cap1,Nod *&cap2)
{
    Nod *p=cap1;
    
    while(p->next!=0)
    {
        p=p->next;
    }
    p->next=cap2;

}

void interclasare(Nod *&cap1,Nod *&cap2)
{   
    Nod *p1=cap1;
    Nod *p2=cap2;
    Nod *aux;
    Nod *q;
    
    while(p1 && p2)
    {
        if(cap1==0 || (cap1->val>cap2->val))
        {
            p2=p2->next;
            cap2->next=cap1;
            cap1=cap2;
            cap2=p2;
        }

        if(p1->next && (p1->next->val>p2->val))
        {
            aux=p2->next;
            p2->next=p1->next;
            p1->next=p2;
            p2=aux;
        }
        else 
        {   q=p1;
            p1=p1->next;
        }

    }

    if(p2)
    {
       q->next=p2;
    }   

    
}
