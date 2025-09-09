#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "functii.h"
#include <crtdbg.h>
using namespace std;

int main()
{
    int x;
    Nod *r=0;
    //a
    cout<<"Dati valori ,pana la 0 \n >> ";
    cin>>x;
    while(x)
    {   
        r=insert(r,x);
        cin>>x;
    }

    //b
    cout<<"Inordine>> \n";
    inordine(r);
    cout<<endl;

    //c
    /*cout<<"Dati o valoare pentru a verifica daca exista in arbore\n";
    cin>>x;
    if(cautare(r,x)==0)
    {
        cout<<"Nu a fost gasit nodul in arbore\n";
    }
    else
    {
        cout<<"Nodul exista in arbore\n";
    }
    cout<<endl;
    
    
    //d
    
    cout<<"Dati o valoare pentru a fi stearsa\n";
    cin>>x;
    stergere(r,x);
    cout<<"Afisarea in inordine\n";
   */ 
  inordine(r);
    cout<<endl;
    

   //e
   cout<<"Nodul de cheie minima este : "<<nod_min(r)<<endl;
   cout<<"Nodul de cheie maxima este : "<<nod_max(r)<<endl;
   
   //f
   int tab=0;
   afisare_identata(r,tab);

    
   

    cout<<"Inaltimea = ";
    cout<<inaltime(r);
    return 0;
//g
    dealocare(r);
}