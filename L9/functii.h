#ifndef DOC_H
#define DOC_H

struct Nod
{
    int data;
    Nod *st,*dr;
};

Nod *insert(Nod *r,int a);
void inordine(Nod *r);
Nod *make(int a);
bool cautare(Nod *r,int x);
void delete_root(Nod *&r);
void stergere(Nod *&r, int x);
Nod *removeGreatest(Nod *&r);
int nod_min(Nod *r);
int nod_max(Nod *r);
void afisare_identata(Nod *r,int tab);
void dealocare(Nod *&r);
int inaltime(Nod *r);

#endif