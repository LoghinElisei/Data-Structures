#ifndef DOC_H
#define DOC_H

#define M 87
struct Nod
{
    char *key;
    Nod *next;
};

void initHT(Nod *HT[]);
bool inserare(Nod *HT[],char *key);
Nod *cautare(Nod *HT[],char *key);
int fdispersie(char *key);
void afisare(Nod *HT[]);
bool stergere(Nod *HT[],char *key);
double grad_clasterizare(Nod *HT[],int N);

#endif