#include <iostream>
#include "functii.h"
#include <fstream>
using namespace std;
ifstream fin("date.in");

int main(void)
{
    Nod *cap=0;
    char nume[100];
    int n,p0,m,save;

    cout<<"Dati numarul persoanelor"<<endl;
    fin>>n;
    cout<<"Dati numele persoanelor care participa , pana la apasarea tastei 0 :"<<endl;
    for(int i=1;i<=n;i++)
    {
        fin>>nume;
        inserare(cap,nume);
    }

    cout<<"Cercul este format din :"<<endl;
    afisare(cap);

    cout<<"Dati o pozitie de unde incepe jocul si o pozitie de unde incepe executarea :"<<endl;
    fin>>p0>>m;
    Joseph(cap,p0,m);

    cout<<"Introduceti pozitia unei persoane pe care doriti sa o salvati :"<<endl;
    fin>>p0;
    save=salvare(n,m,p0);
    cout<<"Pozitia de incepere pentru a salva persoana este :"<<save<<endl;

    //testare
    //Joseph(cap,save,m);
    return 0;
}