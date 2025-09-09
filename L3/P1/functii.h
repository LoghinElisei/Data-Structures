#ifndef TEST_H
#define TES_H

struct Nod{
    int val;
    Nod *next;
};

bool insert(Nod *&cap ,int x);
void afisare(Nod *cap);
bool verificare(Nod *cap);
bool inserarePozitie(Nod *&cap);
bool stergere(Nod *&cap);
void afisare_inversa(Nod *p);
bool parcurgere_bi(Nod *p);
bool bucle(Nod *p);
void mijloc(Nod *cap);
void inversareLegaturi(Nod *&cap);
#endif