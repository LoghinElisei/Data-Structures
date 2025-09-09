#include <iostream>
#include "functii.h"
using namespace std;

bool inserare(Nod *&cap,int x)
{
    Nod *p=new Nod;
    if(p==0)
    {
        cout<<"Eroare la alocare "<<endl;
        return 0;
    }
    p->val=x;
    if(cap==NULL)
    {
        cap=p;
        p->next=NULL;
        p->prev=NULL;
    }
    else
    {  
         p->next=cap;
        cap->prev=p;
        p->prev=NULL;
        cap=p;
    }
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

bool inserarePoz(Nod *&cap,int val,int poz)
{
    Nod *p=new Nod;
    Nod *q=cap;
    if(p==NULL)
    {
        cout<<"Eroare alocare";
        return 0;
    }
    p->val=val;
    if(poz==1)
    {
        p->next=cap;
        cap->prev=p;
        p->prev=NULL;
        cap=p;
    }
    
    if(poz==2)
    {
        p->next=cap;
        p->prev=NULL;
        cap->prev=p;
        cap=p;

        return 1;
    }
    while(q->next && poz>2)
    {
        q=q->next;
        poz--;
    }
    if(poz==1)
    {
        cout<<"Pozitie gresita"<<endl;
        return 0;
    }
    
    p->next=q->next;
    p->next->prev=p;
    q->next=p;
    p->prev=q;

    return 1;
}

bool stergere(Nod *&cap,int poz)
{
    Nod *p=cap;
    Nod *q;
    if(poz==1)
    {
        cout<<"Pozitie gresita"<<endl;
        return 0;
    }

    if(poz==2)
    {
        cap=cap->next;
        delete p;
        p=0;
        return 1;
    }
    while(p->next && poz>2)
    {
        poz--;
        p=p->next;
    }

    q=p->next;
    p->next=q->next;
    
    if(q->next !=0)
    {
        q->next->prev=p;
    }
    delete q;
    q=0;

    return 1;

}
