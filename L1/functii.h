#ifndef TEST_H
#define TES_H

struct Nod{
    int val;
    Nod *next;
};

bool insert(Nod *&cap ,int x);
void afisare(Nod *cap);
bool verificare(Nod *cap,int x);
void inserarePozitie(Nod *cap,int poz,int n);
#endif