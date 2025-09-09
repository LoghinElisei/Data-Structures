#include <iostream>
#include "functii.h"

using namespace std;

int main(void)
{
    int *v=0;
    int n=1;
    int N=0;
    int x,i;
    int aux;
    cout<<"n = ";
    cin>>n;

    v=new int [n];
    if(v==0)
    {
        fprintf(stderr,"Memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }
    for (i=1;i<=n;i++)
    {
        v[i]=0;
    }
    cout<<"Dati valorile arborelui\n";
    
    for (i=1;i<=n;i++)
    {
        cin>>x;
        inserare(v,N,x);
    }
    N=n;
    cout<<"\tInordine\n";
    inordine(v,N,1);
    cout<<endl;
    

    cout<<"\tVectorul arborelui\n";
    for(i=1;i<=n;i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;

    cout<<"\tVectorul sortat\n";
    heapsort(v,n);
    for(i=1;i<=n;i++)
    {
        cout<<v[i]<<' ';
    }
    //delete []v;

    return 0;
}