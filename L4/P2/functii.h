#ifndef TEST_H
#define TEST_H

struct Nod{
    int val;
    Nod *next;
};

void afisare(Nod *cap);
bool inserare(Nod *&cap,int val);
void permutari(Nod *cap);
void inversare(Nod *&cap);

#endif