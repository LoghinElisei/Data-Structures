#include <iostream>
#include "functii.h"
using namespace std;

Nod *insert(Nod *r,int a)
{
    if(r==0)
    {
      r=make(a);
      return r;
    }
    else
    {
        if(a<r->data)
        {
            r->st=insert(r->st,a);
        }
        else if(a>r->data)
        {
            r->dr=insert(r->dr,a);
        }
    }
    return r;
}

Nod *make(int a)
{   
    Nod *p=new Nod;
    if(p==NULL)
    {   
        cout<<"Memorie insuficienta\n";
        exit(EXIT_FAILURE);
    }

    p->data=a;
    p->st=0;
    p->dr=0;
    
    return p;
}

void inordine(Nod *r)
{
    if(r!=0)
    {
        inordine(r->st);
         
        inordine(r->dr);
       cout<<r->data<<' ';
    }
}

bool cautare(Nod *r,int x)
{
    
    if(r!=0)
    {
        if(x == r->data)
        {
            return 1;
        }
        if(x < r->data)
        {
            return cautare(r->st,x);
        }
        else
        {
            return cautare(r->dr,x);
        }
    }
    
    return 0;
}



void stergere(Nod *&r, int x)
{
    if(r==0)
    {
        cout<<"Nu exista nodul in arbore\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        if(x < r->data)
        {
            stergere(r->st,x);
        }
        else
        {
            if(x > r->data)
            {
                stergere(r->dr,x);
            }
            else
            {
                delete_root(r);
            }
        }
    }
}

void delete_root(Nod *&r)
{
    Nod *p=r;
    if(r->st==0)  // daca are fiu dr sau este frunza
    {
        p=r->dr;
        delete r;
        r=p;
    }
    else 
    {   if(r->dr==0)  //are doar fiu stg
        {
           p=r->st;
           delete r;
           r=p;
        }
        else   //are 2 fii
        {
            p=removeGreatest(r->st);
            p->st=r->st;
            p->dr=r->dr;
            delete r;
            r=p;
        }
    }
}
Nod *removeGreatest(Nod *&r)
{
    Nod *p;
    if(r==0)
    {
        return 0;
    }
    else if(r->dr==0)
    {
        p=r;
        r=r->st;
        return p;
    }
    else
    {
        return removeGreatest(r->dr);
    }
}

int nod_min(Nod *r)
{
    if(r->st==0)
    {
        return r->data;
    }
    return nod_min(r->st);
}

int nod_max(Nod *r)
{
    if(r->dr==0)
    {
        return r->data;
    }
    return nod_max(r->dr);
}

void afisare_identata(Nod *r,int tab)
{
    if(r!=0)
    {
        for(int i=0;i<tab;i++)
        {
            cout<<'\t';
        }
        cout<<r->data<<endl;
        
        if(r->st==0)
        {
            for(int i=0;i<tab+1;i++)
            {
            cout<<'\t';
            }
            cout<<'-'<<endl;
        }
        else
        {   
            afisare_identata(r->st,tab+1);    
        }

        if(r->dr==0)
        {   
            for(int i=0;i<tab+1;i++)
            {
            cout<<'\t';
            }
            cout<<'-'<<endl;

        }
        else
        {
            afisare_identata(r->dr,tab+1);
        }
    }
}

void dealocare(Nod *&r)
{
    if(r!=0)
    {
        dealocare(r->st);
       
        dealocare(r->dr);
         delete r;
    }
}

int inaltime(Nod *r)
{
    if(r == 0)
    {
        return 0;
    }
    if(r ->st == 0 )
    {
        if(r->dr ==0)
        {
            return 1;
        }
        else
        {
            return 1+inaltime(r->dr);
        }
    }
    else
    {
        int h1=inaltime(r->st);
        if(r->dr ==0 )
        {
            return h1+1;
        }
        else
        {
            int h2=inaltime(r->dr);
            return 1+max(h1,h2);
        }
    }
}