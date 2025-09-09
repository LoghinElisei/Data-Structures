#include <iostream>
#include "functii.h"
using namespace std;

int main(void)
{
    Nod *cap=0;
    char nume[100];
    int tel,reluare=1;
    
    cout<<"Scrieti numele si numarul de telefon pana la apasarea tastei 0"<<endl;
    cin>>nume>>tel;
    while(tel && nume)
    {

        inserare(cap,nume,tel);
        cin>>nume>>tel;
    }

    while(reluare)
    {
        meniu(cap);
        cout<<"Apasati 1 pentru reluarea programului , 0-oprire"<<endl;
        cin>>reluare;
    }
   
    return 0;


}