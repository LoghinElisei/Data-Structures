#include <iostream>
#include "functii.h"
using namespace std;

int main(void)
{
    Nod *cap=0;
    int val,option;
    cout<<"\t---Prima lista---"<<endl<<"Introduceti valori pana la apasarea tastei 0"<<endl;
    cin>>val;

    while(val)
    {
        inserare(cap,val);
        cin>>val;
    }


    cout<<"\t---A doua lista---"<<endl<<"Introduceti valori pana la apasarea tastei 0"<<endl;
    cin>>val;
    Nod *cap2=0;
    while(val)
    {
        inserare(cap2,val);
        cin>>val;
    }

    afisare(cap,1);
    afisare(cap2,2);

    cout<<"Apasati 1 pentru concatenarea celor 2 liste , 2 pentru interclasearea lor "<<endl;
    cin>>option;
    
    if(option==1)
    {
       concatenare(cap,cap2);
       afisare(cap,3);
    }
    else if(option==2)
    {
        interclasare(cap,cap2);
        afisare(cap,4);
    }
}