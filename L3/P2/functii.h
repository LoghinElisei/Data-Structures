#ifndef TEST_H
#define TEST_H

struct Nod
{
    char nume[100];
    int tel;
    Nod *next;
};

void afisare(Nod *cap);
bool inserare(Nod *&cap,char n[],int t);
void stergere(Nod *&cap,char nume[]);

void cautare(Nod *cap,char nume[]);
void meniu(Nod *&cap);

#endif