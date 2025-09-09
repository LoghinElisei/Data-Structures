#pragma once

struct Nod {
	char data;
	Nod* stg, *drt;
};

Nod* creareArbore();

struct Element{
	Nod *nod;
	Element *next;
};

struct Queue{
	Element *head,*tail;
	
};


void inordine(Nod *p);
void postordine(Nod *p);
Nod *get(Queue &q);
void put(Queue &q,Nod *nod);
int isEmpty(Queue q);
void afisare_pe_niveluri(Nod *root);
int depth(Nod *root);
void noduri_interne(Nod *root,int &nr);
int nr_frunze(Nod *root);
char cautare_max(Nod *root);
char st_vs_dr(Nod *root);
