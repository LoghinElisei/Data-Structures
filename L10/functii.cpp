#include <iostream>
#include "functii.h"
using namespace std;

void RSS(AVL *&a)
{
    AVL *b;
    b=a->dr;
    a->dr=b->st;
    b->st=a;
    a->bf=b->bf=0;
    a=b;
}

void RSD(AVL *&a)
{
    AVL *b;
    b=a->st;
    a->st=b->dr;
    b->dr=a;
    a->bf=b->bf=0;
    a=b;
}

void RDD(AVL *&a)
{
    AVL *b,*c;
    b=a->st;
    c=b->dr;
    switch(c->bf)
    {
        case 0:  //h(t2s)==h(t2d)
                a->bf=b->bf=0;
                break;
        case -1: //h(t2s)<h(t2d)
                a->bf=0;
                b->bf=1;
                break;
        case 1: //h(t2s)>h(t2d)
                a->bf=-1;
                b->bf=0;
                break;
    }

    a->st=c->dr;
    b->dr=c->st;
    c->bf=0;
    c->dr=a;
    c->st=b;
    a=c;
}

void RDS(AVL *&a)
{
    AVL *b,*c;
    b=a->dr;
    c=b->st;
    switch(c->bf)
    {
        case 0:  //h(t2s)==h(t2d)
                a->bf=b->bf=0;
                break;
        case -1: //h(t2s)<h(t2d)
                a->bf=1;
                b->bf=0;
                break;
        case 1: //h(t2s)>h(t2d)
                a->bf=-1;
                b->bf=0;
                break;
    }

    a->dr=c->st;
    b->st=c->dr;
    c->bf=0;
    c->st=a;
    c->dr=b;
    a=c;
}

void inordine(AVL *a)
{
    if(a)
    {
        inordine(a->st);
        cout<<a->data<<' ';
        inordine(a->dr);
    }
}

bool EqRequired=0;
void echilibrare(AVL *&a,int x,bool stg)
{
    if(EqRequired==true)
    {   
       if (stg==true) //daca inserarea valorii s-a facut la stanga
        {
            switch(a->bf)
            {   
                case 1: //adancimea pe SAS era mai mare ->rotatie dreapta
                    EqRequired=false;
                    if(x < (a->st->data))
                    {
                        RSD(a);
                    }
                    else
                    {
                        RDD(a);
                    }
                    break;
                case 0: //nu exista dezechilibru inainte de inserare
                    a->bf=1;
                    break;
                case -1: //adancimea pe SAD era mai mare
                    a->bf=0;
                    EqRequired=false;
                    break;
            }
        }
        else //inserarea s-a facut la dreapta
        {
        switch(a->bf)
        {
            case -1:
                EqRequired=false;
                if(x > (a->dr->data))
                {
                    RSS(a);
                }
                else
                {   
                    RDS(a);
                }
                break;
            case 0:
                a->bf=-1;
                break;
            case 1:
                a->bf=0;
                EqRequired=false;
                break;
            }

        }
    }
}

AVL *MakeNodAVL(int x)
{
    AVL *p=new AVL;
    if(p==0)
    {
        fprintf(stderr,"Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }

    p->data=x;
    p->st=0;
    p->dr=0;
    p->bf=0;
    return p;
}
void inserare(AVL *&a,int x)
{
    if (a==0)
    {
        a=MakeNodAVL(x);
        EqRequired=true;
    }
    else
    {
        if(x< a->data)
        {
            inserare(a->st,x);
            echilibrare(a,x,true);
        }
        else
        {
            if(x> a->data)
            {
                inserare(a->dr,x);
                echilibrare(a,x,false);
            }
        }
    }
}
void afisare_identata(AVL *r,int tab)
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

void dealocare(AVL *&r)
{
    if(r != 0)
    {
        dealocare(r->st);
        dealocare(r->dr);
        delete r;
    }
}

