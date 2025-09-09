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

bool verificare(Nod *cap)
{
    int x;
    cout<<"Dati un numar , pentru a verifica daca se afla in lista "<<endl;
    cin>>x;
    while(cap)
    {
        if(cap->val==x)
        {
            cout<<"Numarul se afla in lista "<<endl;
            return 1;
        }
        cap=cap->next;
    }
    cout<<"Numarul nu se afla in lista "<<endl;
    return 0;
}

bool inserarePozitie(Nod *&cap)
{
    int n,poz;
    cout<<"Dati un numar si o pozitie pentru inserare"<<endl;
    cin>>n>>poz;

    int i=0;
    Nod *p=new Nod;
    Nod *q;
    if(!p)
    {
        cout<<"Eroare la alocare\n";
        return 0;
    }

    p->val=n;
    q=cap;

    if(poz==0)
    { p->next=cap;
      cap=p;
    }
    else
    {
        while(i<(poz-1) && q->next)
        {
            q=q->next;
            i++;
        }

    p->next=q->next;
    q->next=p;
    }

    return 1;
}

bool stergere(Nod *&cap)
{
    int poz;
    cout<<"Dati o pozitie pentru stergere"<<endl;
    cin>>poz;

    Nod *p;
    Nod *q;
    q=cap;
    int i=0;
    if(poz==0)
    { 
        p=cap;
        cap=cap->next;
        delete p;
        p=0;
    }
    else
    {
        while(i<(poz-1) && q->next)
        {
            q=q->next;
            i++;
        }
        if(q->next==0)
        {
            cout<<"Pozitie gresita "<<endl;
            return 0;
        }

        p=q->next;
        q->next=p->next;
        delete p;
        p=0;

    }

    return 1;
}

void afisare_inversa(Nod *cap)
{
    int poz,i;
    cout<<"Dati o pozitie pentru a afisa valoarea nodului , de la coada la cap"<<endl;
    cin>>poz;
    i=poz;

    Nod *p=cap;
    Nod *q=cap;

    while(poz && q->next)
    {
        poz--;
        q=q->next;
    }

    while(q->next)
    {
        p=p->next;
        q=q->next;
    }

    cout<<"Elementul aflat pe pozitia "<<i<<" de la coada la cap este : "<<p->val<<endl;

}

bool parcurgere_bi(Nod *p)
{
    bool x;
    if(p==0)
        return 0;

    cout<<p->val<<' ';
    x=parcurgere_bi(p->next);
    cout<<p->val<<' ';

    return x;
    
}

bool bucle(Nod *cap)
{
    Nod *p=cap;
    Nod *q=cap->next;

    if(q==NULL)
        return false;
    
    while(q->next!=0)
    {
        if(q->next->next==0)
           return false;
        if(p==q)
            return true;
       p=p->next;
       q=q->next->next;
    }

    return false;
}

void mijloc(Nod *cap)
{
    Nod *p=cap;
    Nod *q=cap;

    while(q->next && q->next->next)
    {
        p=p->next;
        q=q->next->next;
    }

    cout<<"Mijlocul listei are valoarea : "<<p->val<<endl;
}

void inversareLegaturi(Nod *&cap)
{
    Nod *p=0;
    Nod *q=cap;
    Nod *r;

    while(q)
    {   r=q->next;
        q->next=p;
        p=q;
        q=r;
    }

    cap=p;
}