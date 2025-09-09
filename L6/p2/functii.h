#ifndef DOC_H
#define DOC_H

struct Element{
    int data;
    Element *next;
};

struct Queue{
    Element *tail,*head;
};

void initQueue(Queue& Q);
void put(Queue& Q, int a);
int get(Queue& Q);
int front(Queue& Q); 
int isEmpty(Queue& Q);

#endif