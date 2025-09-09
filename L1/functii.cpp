#include "functii.h"
#include <iostream>
using namespace std;

bool insert(Nod *&cap ,int x)
{
    Nod *p;
    p=new Nod;
    if(p==0)
    {
        cout<<"Eroare la alocare\n";
        return 0;
    }
    p->val=x;
    p->next=cap;
    cap=p;

    return 1;
}

void afisare(Nod *cap)
{
    while(cap)
    {
        cout<<cap->val<<' ';
        cap=cap->next;
    }
    cout<<endl;
}

bool verificare(Nod *cap,int x)
{
    while(cap)
    {
        if(cap->val==x)
        {
            return 1;
        }
        cap=cap->next;
    }
    return 0;
}

void inserarePozit1 (Nod *cap,int poz,int n)
{
    int i=1;
    Nod *p=new Nod;
    Nod *q=new Nod;
    p->val=n;
    q=cap;

    while(i<(poz-1))
    {
        q=q->next;
        i++;
    }
    p->next=q->next;
    q->next=p;

}

