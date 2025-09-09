#include <iostream>
#include "functii.h"
using namespace std;

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

void inserare(int *v,int &n,int x)
{
    n++;
    v[n]=x;
    int parinte = n/2;
    int copil =n;

    while ((v[parinte] > v[copil]) && (parinte>=1))
    {
        swap(v[parinte],v[copil]);
        copil=parinte;
        parinte=parinte/2;
    }
}

int stergere(int *v,int &n)
{
    
    if(n==0)
    {
        fprintf(stderr,"Arborele este vid\n");
        exit(EXIT_FAILURE);
    }

    int x=v[1];
    v[1]=v[n];
    n--;
    int parinte=1;
    int copil=2;

    while(copil<=n)
    {
        if(((copil+1)<n) && v[copil+1] < v[copil])
        {
            copil++;
        }
        
        if(v[copil] < v[parinte])
        {
            swap(v[copil],v[parinte]);
            parinte=copil;
            copil=parinte*2;
        }
        else
        {
            copil=n+1;
        }
    }
    return x;

}


void dijkstra(int **a,int n,int start,int *dist,int *prev)
{
    //voi folosi un minheap pentru a stoca nodurile de drum minim
    int N=0;
    int u;
    long alt;
    int *viz=alocareVector(n);
    int *min_heap=alocareVector(n+1);

    for(int i=0;i<n;i++)
    {
        dist[i]=LONG_MAX;
        viz[i]=0;
        prev[i]=-1;
        inserare(min_heap,N,i);
    }

    dist[start]=0;
    //inserare(min_heap,N,0);
    
    while(N !=0 )
    {
        u=stergere(min_heap,N);
        
        if(viz[u] == 0)
        {
            viz[u]=1;


            for(int j=0;j<n;j++)
            {
                if(a[u][j] !=0 )
                {
                    alt=dist[u]+a[u][j];
                    if(alt < dist[j])
                    {
                        dist[j]=alt;
                        prev[j]=u;
                      
                        inserare(min_heap,N,j); //sau alt ?
                    }
                }
            }
        }
    }
}

void prelucrare_dijkstra(int *prev,int *dist,int n,int start,int stop)
{
    if(stop>n)
    {
        fprintf(stderr,"Nodul nu exista \n");
        exit(EXIT_FAILURE);
    }
        
    int cost=0;
    int i=0;
    int *v=alocareVector(n);
    stop--;
    int k=stop;
    cout<<"Costul drumului de la nodul "<<start+1<<" la nodul "<<stop+1<<" este : ";
    cost=dist[stop];
    cout<<cost<<endl;

    while (k != start)
    {
        v[i]=k;
        k=prev[k];
        i++;
    }

    cout<<"Drumul parcurs de la nodul "<<start+1<<" la nodul "<<stop+1<<" este : \n>> ";
    cout<<start+1<<' ';
    for(int k=i-1;k>=0;k--)
    {
        cout<<v[k]+1<<' ';
    }
    cout<<endl;
}