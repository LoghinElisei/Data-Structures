#include <iostream>
#include "functii.h"
using namespace std;

int main(void)
{   int n;
    Nod *cap=0;

    cout<<"Introduceti pana la valoarea 0"<<endl;
    cin>>n;

    while(n)
    {
        insert(cap,n);
        cin>>n;
    }

    afisare(cap);

    inserarePozitie(cap,3,97);

    afisare(cap);


    return 0;
}