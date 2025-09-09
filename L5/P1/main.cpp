#include <iostream>
#include "functii.h"
using namespace std;

int main(void)
{
    stack s;
    int n,i,val;

    initStack(s);
    
    if(isEmpty(s))
    {
        cout<<"Stiva este goala , dati valori \n";
    }

    cout<<"Dati numarul de elemente si elementele :\n>> ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>val;
        push(s,val);
    }

    if(!isEmpty(s))
       cout<<"Varful stivei are valoarea : "<<top(s)<<endl;

    cout<<"Elementele stivei sunt :";
    for(i=0;i<n;i++)
    {
        cout<<pop(s)<<' ';
    }
   
    cout<<endl;
}