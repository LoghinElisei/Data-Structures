#include <iostream>
#include "functii.h"
using namespace std;

int main()
{
    AVL *a=0;
    int x;
    cout<<"Dati valori pana la 0\n>> ";
    cin>>x;
    while(x)
    {
        inserare(a,x);
        cin>>x;
    }

    cout<<"\tInordine\n";
    inordine(a);
    cout<<endl;

    int tab=0;
    afisare_identata(a,tab);
    
    //11 22 33 44 55 40 30 20 10 21 0

    dealocare(a);
    a=0;
    
    return 0;

}