#ifndef TEST_H
#define TEST_H

struct Nod{
    int val;
    Nod *next;
};
bool inserare(Nod *&cap,int x);
void afisare(Nod *cap,int x);
void concatenare(Nod *&cap1,Nod *&cap2);
void interclasare(Nod *&cap1,Nod *&cap2);
#endif