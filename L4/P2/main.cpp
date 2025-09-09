#include <iostream>
#include "functii.h"
using namespace std;

int main(void)
{
    Nod *cap=0;
    int n;
    cout<<"Dati valori pana la valoarea 0"<<endl;
    cin>>n;
    while(n)
    {
        inserare(cap,n);
        cin>>n;
    }
    cap=cap->next;
    
    cout<<"Lista este :"<<endl;
    afisare(cap);

    cout<<"Lista cu permutari este:"<<endl;
    permutari(cap);

    cout<<"Lista inversata este:"<<endl;
    inversare(cap);
    afisare(cap);
    
    return 0;

}