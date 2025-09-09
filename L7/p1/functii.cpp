#include <iostream>
#include "functii.h"
#include <string.h>
using namespace std;

void initHT(Nod *HT[])
{
    int i;
    for(i=0;i<M;i++)
    {
        HT[i]=0;
    }
}

int fdispersie(char *key)
{
    int suma=0,i;

    for(i=0;i<strlen(key);i++)
    {
        suma=suma+*(key+i);
    }

    return (suma%M);
}

Nod *cautare(Nod *HT[],char *key)
{
    int h=fdispersie(key);
    Nod *p;
    p=HT[h];
    while(p)
    {
        if(strcmp(key,p->key)==0)
        {
            return p;
        }
        p=p->next;
    }
    return 0;
}

bool inserare(Nod *HT[],char *key)
{
    Nod *p=new Nod;
    Nod *q;
    int h;
    p->key=key;
    h=fdispersie(key);

    if(HT[h]==0)  //nu exista val cu codul de dispersie h
    {
        HT[h]=p;
        p->next=0;
        return 1;
    }
    else
    {
        q=cautare(HT,key);
        if(q==0) //nu exista cheia key
        {
            p->next=HT[h];
            HT[h]=p;
            return 1;

        }
        else
        {
            cout<<"Elementul exista deja :"<<key<<endl;
            delete p;
            return 0;
         }
    }
}

void afisare(Nod *HT[])
{
    int i;
    Nod *p;

    for(i=0;i<M;i++)
    {
        if(HT[i]!=0)
        {
           cout<<"Inregistrari cu codul de dispersie : "<<i<<endl;
           p=HT[i];
           while(p)
           {
                cout<<p->key<<' ';
                p=p->next;
           }
           cout<<endl;
        }
    }
}

bool stergere(Nod *HT[],char *key)
{
    Nod *q,*p;
    p=cautare(HT,key);
    int h;

    if(p==0)
    {
        cout<<"Cheia nu a fost gasita\n";
        return 0;
    }
    
    h=fdispersie(key);
    q=HT[h];
    if(q==p) //eliminare prima pozitie din lista
    {
        HT[h]=q->next;
        delete q;
    }
    else //oricare alta pozitie
    {
        while(q->next!=p)
        {
            q=q->next;
        }
        q->next=p->next;
        delete p;
    }
    return 1;
}