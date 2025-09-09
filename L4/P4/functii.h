#ifndef TEST_H
#define TEST_H

struct Nod{
    char nume[100];
    Nod *next;
};
void afisare(Nod *cap);
bool inserare(Nod *&cap,char s[]);
void Joseph(Nod *&cap,int p0,int m);
int salvare(int n,int m,int persoana);

#endif