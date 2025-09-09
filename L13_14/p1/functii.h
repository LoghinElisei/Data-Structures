#ifndef DOC_H
#define DOC_H

struct stack{
    int data;
    stack *next;
};

struct Element{
    int data;
    Element *next;
};

struct Queue{
    Element *head,*tail;
};

void afisareMatrice(int **a,int n);
void DFS_rec(int **a,int n,int i,int *M,int *L);
void afisareVector(int *v,int n);
int *alocareVector(int n);
int pop(stack *&s);
void push(stack *&s,int x);
void initStack(stack *&s);
int isEmpty(stack *s);
void DFS(int **a,int n,int i,int *M,int *L,int k) ;
void zerorizare(int *v,int n);
int get(Queue &q);
void put(Queue &q,int x);
void init_q(Queue &q);
int is_empty_q(Queue q);
void BFS_rec(int **a,int n,Queue &q,int *M);
void BFS(int **a,int n,int *M);

#endif