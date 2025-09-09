#include <iostream>
#include "functii.h"
using namespace std;

int main(void)
{
    Queue q;
    initQueue(q);
    int n,i,x;

    //1
    cout<<"Dati numarul de elemente\n:>> ";
    cin>>n;
    cout<<"Dati elementele\n>> ";
    for(i=0;i<n;i++)
    {
        cin>>x;
        put(q,x);
    }

    //2
    cout<<"Elementul eliminat din coada este \n>> ";
    cout<<get(q)<<endl;

    //3
    cout<<"Elementul din fata cozii este\n>> ";
    cout<<front(q)<<endl;

    return 0;
}