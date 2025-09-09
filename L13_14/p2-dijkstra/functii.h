#ifndef DOC_H
#define DOC_H

int stergere(int *v,int &n);
void inserare(int *v,int &n,int x);
int *alocareVector(int n);
void afisareVector(int *v,int n);
void afisareMatrice(int **a,int n);
void dijkstra(int **a,int n,int start,int *dist,int *prev);
void prelucrare_dijkstra(int *prev,int *dist,int n,int start,int stop);


#endif