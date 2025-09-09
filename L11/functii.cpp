#include <iostream>
#include "functii.h"
using namespace std;

void inserare(int *v,int &n,int x)
{
    int fiu,parinte;
    v[++n]=x;
    fiu=n;
    parinte=n/2;

    while(parinte >=1)
    {
        if(v[parinte] < v[fiu])
        {
            swap(v[parinte],v[fiu]);
            fiu=parinte;
            parinte=fiu/2;

        }
        else // inseamna ca am terminat , iesim din bucla
        {
            parinte =0;
        }
    }
}

void inordine (int *v,int n,int i)
{
    if(i<=n)
    {
        inordine(v,n,i*2);
        cout<<v[i]<<' ';
        inordine(v,n,i*2+1);
    }  
}

int eliminare(int *v,int &n)
{
    if(n==0)
    {
        fprintf(stderr,"Arborele este vid\n");
        exit(EXIT_FAILURE);
    }
    else
    {   int x=v[1];
        v[1]=v[n];
        n=n-1;
        int parinte=1;
        int copil=2;

        while(copil<=n)
        {
            if( ((copil+1)<=n) && (v[copil]<v[copil+1])) // verificam daca mai avem fii si max(fii)
            {
                copil++;
            }
            if(v[copil] > v[parinte])  //parinte < max(fii)
            {
                swap(v[copil],v[parinte]);
                parinte=copil;
                copil=copil*2;
            }
            else 
            {
                copil=n+1;
            }
        }
        return x;
    }

}

int *heapsort(int *v,int n)
{
    int i;
    int N=n;
    for(i=n;i>=1;i--)
    {
        v[i]=eliminare(v,N);
    }

    return v;
}