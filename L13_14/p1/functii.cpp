#include <iostream>
#include <fstream>
#include "functii.h"
using namespace std;
#include "limits.h"

void afisareMatrice(int **a,int n)
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}

void afisareVector(int *v,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

int *alocareVector(int n)
{
    int *L=0;
    L=new int[n];
    if(0 == L)
    {
        fprintf(stderr,"Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }

    for (int i=0;i<n;i++)
    {
        L[i]=0;
    }

    return L;
}

int t=0;
void DFS_rec(int **a,int n,int i,int *M,int *L)
{
    int k;
    L[t]=i;
    t++;
    M[i]=1;

    for(k=0;k<n;k++)
    {
        if(a[i][k]==1)
        {
            if(M[k]==0)
            {
                DFS_rec(a,n,k,M,L);
            }
        }
    }

}

int isEmpty(stack *s)
{
    return s==0;
}

void initStack(stack *&s)
{
    s=0;
}
void push(stack *&s,int x)
{
    stack *p=new stack;
    
    if(0 == p)
    {
        fprintf(stderr,"Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }

    p->data=x;
    p->next=s;
    s=p;

}
int pop(stack *&s)
{
    

    if(isEmpty(s) == 0)
    {
        stack *p;
        int x;
        x=s->data;
        p=s;
        s=s->next;
        delete p;
        return x;
    }
    else
    {
        fprintf(stderr,"stiva goala\n");
        exit(EXIT_FAILURE);
    }
    
}

void DFS(int **a,int n,int i,int *M,int *L,int r)  //M-vizite L-lista parcurgere
{
    int j;
    stack *s;
    initStack(s);
    push(s,i);
    while(!isEmpty(s))
    {
        j=pop(s);
        if(M[j]==0)
        {
            L[r]=j;
            r++;
            M[j]=1;
            for (int k=0;k<n;k++)
            {
                if(a[j][k]==1)
                {
                    push(s,k);
                }

            }
            
        }
    }
}

void zerorizare(int *v,int n)
{
    for(int i=0;i<n;i++)
    {
        v[i]=0;
    }
}

int is_empty_q(Queue q)
{
    return ( q.head ==0  && q.tail==0);
}

void init_q(Queue &q)
{
    q.head=0;
    q.tail=0;
}

void put(Queue &q,int x)
{
    Element *p=new Element;
    
    if(p==0)
    {
        fprintf(stderr,"Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }

    p->data=x;
    p->next=0;
    if(is_empty_q(q))
    {
        q.tail=p;
        q.head=p;
    }
    else
    {
        q.tail->next=p;
        q.tail=p;
    }
    
    
}

int get(Queue &q)
{
    Element *p;
    int aux;
    if(is_empty_q(q))
    {
        fprintf(stderr,"Coada goala\n");
        exit(EXIT_FAILURE);
    }

    p=q.head;
    aux=p->data;

    if(q.tail == q.head)
    {
        q.tail=0;
        q.head=0;
    }
    else
    {
        q.head=p->next;

    }
    
    delete p;
    return aux;
}

void BFS_rec(int **a,int n,Queue &q,int *M)
{
    if(!is_empty_q(q))
    {
        int j=get(q);
        M[j]=1;
        cout<<j<<' ';

        for (int k=0;k<n;k++)
        {
            if(a[j][k]==1 && M[k]==0)
            {
                put(q,k);
                M[k]=1;
            }
        }
        BFS_rec(a,n,q,M);
    }
}

void BFS(int **a,int n,int *M)
{
    Queue q;
    init_q(q);
    put(q,0);

    while(!is_empty_q(q))
    {
        int j=get(q);
        M[j]=1;
        cout<<j<<' ';
        
        for (int k=0;k<n;k++)
        {
            if(a[j][k]==1 && M[k]==0) //nodul k se adauga in coada daca 
                                    //este vecin al lui j si nu a fost vizitat
            {
                M[k]=1;
                put(q,k);
            }
        }
    }
}