#ifndef TEST_H
#define TEST_H

struct Nod{
    int val;
    Nod *next;
};
bool inserare(Nod *&cap,int val);
void afisare(Nod *cap);
void concatenare(Nod *&cap1,Nod *&cap2);
void interclasare(Nod *cap1,Nod *cap2);

#endif