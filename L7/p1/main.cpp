#include <iostream>
#include "functii.h"
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("dictionar.txt");
ifstream f2in("text.txt");
int main()
{
    Nod *HT[M];
    char *key,a[100];
    //b
    initHT(HT);

    //c
    cout<<"Citirea tabelei\n";
    while(fin>>a)
    {
        key=new char[strlen(a)];
        strcpy(key,a);
        inserare(HT,key);
    }

    afisare(HT);

    //d
    while(f2in>>a)
    {
        key=new char[strlen(a)];
        strcpy(key,a);
        if(cautare(HT,key)==0)
        {
            cout<<"Cuvantul \""<<key<<"\" a fost scris gresit\n";
        }
    }

    //e
    cout<<"Dati un cuvant pentru a-l sterge din tabela \n>> ";
    cin>>a;
    key=new char[strlen(a)-1];
    strcpy(key,a);
    stergere(HT,key);
    
    cout<<"Tabela dupa stergerea cuvantului este \n";
    afisare(HT);
}