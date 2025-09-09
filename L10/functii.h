#ifndef DOC_H
#define DOC_H

struct AVL{
    int bf;
    int data;
    AVL *dr,*st;
};
void inserare(AVL *&a,int x);
AVL *MakeNodAVL(int x);
void echilibrare(AVL *&a,int x,bool stg);
void inordine(AVL *a);
void RDS(AVL *&a);
void RDD(AVL *&a);
void RSD(AVL *&a);
void RSS(AVL *&a);
void afisare_identata(AVL *r,int tab);
void dealocare(AVL *&r);

#endif