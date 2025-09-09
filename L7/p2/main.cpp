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
    int N=0;
    //b
    initHT(HT);

    //c
    cout<<"Citirea tabelei\n";
    while(fin>>a)
    {
        key=new char[strlen(a)];
        strcpy(key,a);
        inserare(HT,key);
        N++;
    }

    afisare(HT);

    cout<<"Gradul de clasterizare este \n>> ";
    cout<<grad_clasterizare(HT,N);

    return 0;
}