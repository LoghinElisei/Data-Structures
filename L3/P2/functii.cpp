#include <iostream>
#include "functii.h"
#include <string.h>
using namespace std;


bool inserare(Nod *&cap, char n[], int t) 
{
    Nod *p = new Nod;
    if (p == 0) 
    {
        cout << "Eroare la alocare" << endl;
        return false;
    }
   
    strcpy(p->nume, n);
    p->tel = t;
    p->next = 0;
   
    if (cap == 0 || strcmp(cap->nume, n) >= 0) {
        p->next = cap;
        cap = p;
        return true;
    }

    Nod *q = cap;
    while (q->next && strcmp(q->next->nume, n) < 0) {
        q = q->next;
    }

    p->next = q->next;
    q->next = p;
    return true;
}

void afisare(Nod *cap)
{
    cout<<"--------------------"<<endl;
    cout<<"Nume\tTelefon"<<endl;
    cout<<"--------------------"<<endl;
    while(cap)
    {   
        cout<<cap->nume<<'\t'<<cap->tel<<endl;
        cap=cap->next;
    }
    
}

void stergere(Nod *&cap,char nume[])
{
    Nod *p=cap;
    Nod *q;
    int poz=0;

    while(strcmp(p->nume,nume)!=0)
    {
        q=p;
        p=p->next;
        poz++;
    }

    if(poz==0)
    {
        cap=cap->next;
        delete p;
        p=0;
    }
    else
    {   
        q->next=p->next;
        delete p;
        p=0;

    }

}

void cautare(Nod *cap,char nume[])
{
    
    while(cap->next!=0 && strcmp(cap->nume,nume)!=0)
    {   
        cap=cap->next;
    }
    if(strcmp(cap->nume,nume)==0)
    {
        cout<<"Numarul de telefon al persoanei "<<cap->nume<<" este "<<cap->tel<<endl;
    }
    else
    {
        cout<<"Persoana nu a fost gasita"<<endl;
    }
}

void meniu(Nod *&cap)
{
    int option,tel;
    char nume[100];
    cout<<"Apasati 1-inserare element , 2-stergere element , 3-cautare nr.tel.in lista dupa nume ,4-afisare lista"<<endl;
    cin>>option;

    switch (option)
    {
        case 1:
            cout<<"Scrieti numele si numarul de telefon pana la apasarea tastei 0"<<endl;
            cin>>nume>>tel;
            inserare(cap,nume,tel);
            break;

        case 2:
            cout<<"Dati numele unei persoane pentru a o sterge din lista "<<endl;
            cin>>nume;
            stergere(cap,nume);
            cout<<"Dupa stergere lista este: "<<endl;
            afisare(cap);
            break;
        
        case 3:
            cout<<"Dati numele unei persoane pentru a cauta numarul ei de telefon"<<endl;
            cin>>nume;
            cautare(cap,nume);
            break;

        case 4:
            afisare(cap);
            break;
    }
}