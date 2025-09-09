#include <iostream>
#include "functii.h"
using namespace std;

int main(void)
{
    Nod *cap=0;

    int n;
    cout<<"Dati elementele listei pana la apasarea tastei 0"<<endl;
    cin>>n;
    
    //1
    while (n)
    {
        inserare(cap,n);
        cin>>n;
    }
    
    //2
    cout<<"Lista este :"<<endl;
    afisare(cap);

    //3
    int val,poz;
    cout<<"Dati o valoare si o pozitie pentru inserare"<<endl;
    cin>>val>>poz;
    inserarePoz(cap,val,poz);
    cout<<"Lista dupa inserare este :"<<endl;
    afisare(cap);
    
    //4
    
    cout<<"Dati o pozitie pentru stergere"<<endl;
    cin>>poz;
    stergere(cap,poz);
    cout<<"Lista dupa stergerea valoarea :"<<endl;
    afisare(cap);

    return 0;
    
}

