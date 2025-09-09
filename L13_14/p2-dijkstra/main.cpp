#include <iostream>
#include <fstream>
#include "functii.h"
using namespace std;
ifstream fin("dataNew.txt");

int main(void)
{
    int fd;
    int n,m;
    int **a=0;
    int x,y,c;
    int *L,*M,*v;
    if(!fin)
    {
        fprintf(stderr,"Eroare la deschiderea fisierului\n");
        exit(EXIT_FAILURE);
    }

    fin>>n;
    a=new int *[n];
    if(0 == a)
    {
        fprintf(stderr,"Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<n;i++)
    {
        a[i]=new int [n];
        if(0 == a)
        {
            fprintf(stderr,"Eroare la deschiderea fisierului\n");
            exit(EXIT_FAILURE);
        }
    }
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }

    fin>>m;
    for (int i=0;i<m;i++)
    {
        fin>>x;
        fin>>y;
        fin>>c;
        if(x>n && y>n)
        {
            fprintf(stderr,"S-au introdus gresit valorile\n");
            exit(EXIT_FAILURE);
        }
        a[x-1][y-1]=c;
    }
    
    afisareMatrice(a,n);
    cout<<endl;

    L=alocareVector(n);
    v=alocareVector(n);

    int *prev=alocareVector(n);
    int *dist=alocareVector(n);
   
    dijkstra(a,n,0,dist,prev);
    
    afisareVector(prev,n);
    afisareVector(dist,n);

    int stop;
    cout<<"Dati un nod de stop : ";
    cin>>stop;

    prelucrare_dijkstra(prev,dist,n,0,stop);
    return 0;
}