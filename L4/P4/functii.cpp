#include <iostream>
#include "functii.h"
#include <string.h>
using namespace std;

bool inserare(Nod *&cap,char s[])
{
    Nod *p=new Nod;

    if(p==NULL)
    {
        cout<<"Eroare la alocare "<<endl;
        return 0;
    }

    strcpy(p->nume,s);

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
    cout<<p->nume<<' ';
    while(p->next!=cap)
    {
        p=p->next;
        cout<<p->nume<<' ';
        
    }
    cout<<endl;
}

void Joseph(Nod *&cap,int p0,int m)
{
    Nod *p=cap;
    Nod *q;
    int aux;
    while(p0>0)
    {
        p=p->next;
        p0--;
    }
    
    while(p->next!=p)
    {
        aux=m;
        
        while(aux>1)
        {
            p=p->next;
            aux--;
        }
        q=p->next;
        p->next=p->next->next;

        cout<<"A fost executata persoana: "<<q->nume<<endl;
        delete q;
        q=0;
    }

}

int salvare(int n,int m,int persoana)
{
    return ((persoana-2+m)%n)+1;
}