#include <iostream>
#include "functii.h"
using namespace std;

int main(void)
{   int n,ok;
    Nod *cap=0;
    int x;

    cout<<"Introduceti pana la valoarea 0"<<endl;
    cin>>n;

    //1
    while(n)
    {
        insert(cap,n);
        cin>>n;
    }
    
    //2
    afisare(cap);

    //3
    verificare(cap);

    //4
    inserarePozitie(cap);
    cout<<"Lista dupa inserare este : ";
    afisare(cap);
    cout<<endl;
  
    //5
    stergere(cap);
    cout<<"Lista dupa stergere este :"<<endl;
    afisare(cap);

    //6
    afisare_inversa(cap);

    //7
    cout<<"Lista in ambele sensuri este :"<<endl;
    parcurgere_bi(cap);
    cout<<endl;

    //8
    //pentru testare
    //cap->next->next->next=cap;

    if(bucle(cap))
    {
        cout<<"Lista are bucle"<<endl;
    }
    else
    {
        cout<<"Lista nu are bucle"<<endl;
    }

    //9
    mijloc(cap);

    //10
    inversareLegaturi(cap);
    cout<<"Lista dupa inversare este : ";
    afisare(cap);
    cout<<endl;
    return 0;
}