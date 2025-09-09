#include <iostream>
#include "functii.h"
using namespace std;

int main(void)
{
    Queue Q;
    //1
    initQueue(Q);
    int n,i,x;
    
    //2
    cout<<"Dati numarul de elemente\n>> ";
    cin>>n;
    cout<<"Dati elementele \n >> ";
    for(i=0;i<n;i++)
    {
        cin>>x;
        put(Q,x);
    }

    //3
    cout<<"Elementul scos afara primul din coada este :\n >> "<<get(Q)<<endl;

    //4
    cout<<"Elementul din capul cozii este \n >> "<<front(Q)<<endl;


}