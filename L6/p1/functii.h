#ifndef DOC_H
#define DOC_H

#define DIMMAX 8

struct Queue{
    int head,tail;
    int vect[DIMMAX]; 
};

void initQueue(Queue &Q);
void put(Queue &Q,int a);
int get(Queue &Q);
int front(Queue &Q);
int isEmpty(Queue &Q);
int NextPos(int pos);

#endif