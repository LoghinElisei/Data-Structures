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
    int *L,*M;

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

    L=alocareVector(n);
    M=alocareVector(n);  //vector vizitare

    cout<<"\tDFS recursiv:\n";
    DFS_rec(a,n,0,M,L);
    afisareVector(L,n);
    cout<<endl;

    zerorizare(M,n);
    zerorizare(L,n);
    cout<<"\tDFS iterativ:\n";
    DFS(a,n,0,M,L,0);
    afisareVector(L,n);
    cout<<endl;

    Queue q;
    init_q(q);
    put(q,0);
    zerorizare(M,n);
    cout<<"\tBFS recursiv\n";
    BFS_rec(a,n,q,M);
    cout<<endl<<endl;

    
    zerorizare(M,n);
    cout<<"\tBFS iterativ\n";
    BFS(a,n,M);
    cout<<endl<<endl;

    

    return 0;
}