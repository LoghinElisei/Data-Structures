#include <iostream>
#include "functii.h"
using namespace std;

int main(void)
{
    Nod *cap1=0;
    Nod *cap2=0;
    int n;
    cout<<"Dati valori pentru lista 1"<<endl;
    cin>>n;
    while(n)
    {
        inserare(cap1,n);
        cin>>n;
    }
    cap1=cap1->next;

    cout<<"Lista 1 este :"<<endl;
    afisare(cap1);

    cout<<"Dati valori pentru lista 2 "<<endl;
    cin>>n;
    while(n)
    {
        inserare(cap2,n);
        cin>>n;
    }
    cap2=cap2->next;

    cout<<"Lista 2 este :"<<endl;
    afisare(cap2);

    /*cout<<"Listele concatenate :"<<endl;
    concatenare(cap1,cap2);
    afisare(cap1);
    */
   
    cout<<"Listele interclasate :"<<endl;
    interclasare(cap1,cap2);
    afisare(cap1);



}