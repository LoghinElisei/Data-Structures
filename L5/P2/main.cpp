#include <iostream>
#include "functii.h"
using namespace std;

int main(void)
{
    stack s;
    int n,i,val;

    cout<<"Dati n : ";
    cin>>n;
    cout<<"Dati elementele \n >> ";
    initStack(s);
    for(i=0;i<n;i++)
    {
        cin>>val;
        push(s,val);
    }

    cout<<"Varful stivei este : "<<top(s)<<endl;

    cout<<"Elementele stivei sunt :\n";
    
    if(!isEmpty(s))
    {
        for(i=0;i<n;i++)
        {
            cout<<pop(s)<<' ';
        }
    }
    else
    {
        cout<<"Stiva este goala";
    }
    cout<<endl;
}