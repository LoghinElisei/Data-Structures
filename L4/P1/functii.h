#ifndef TEST_H
#define TEST_H

struct Nod{
    int val;
    Nod *next,*prev;
};

bool inserare(Nod *&cap,int x);
void afisare(Nod *cap);
bool inserarePoz(Nod *&cap,int val,int poz);
bool stergere(Nod *&cap,int poz);
#endif