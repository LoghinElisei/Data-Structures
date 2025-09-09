#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "Arbore.h"
#include <iostream>
#include <math.h>
using namespace std;

static void eroare();
static char readchar();
static char citesteNume();
static Nod* citesteArbore();

static char car = 0;

static void eroare()
{
	printf("Sirul de intrare este eronat!\n");
	printf("Apasati tasta o tasta...");
	getchar();
	exit(1);
}

static char readchar()
{
	char c;
	do  c = getchar();  while (c == ' ');
	return c;
}

static char citesteNume()
{
	char c;
	if (!isalpha(car)) eroare();
	c = car;
	car = readchar();
	return c;
}

static Nod* citesteArbore()
{
	Nod* rad;
	if (car == '-')
	{
		rad = 0;
		car = readchar();
	}
	else
	{
		rad = new Nod;
		rad->data = citesteNume();
		if (car != '(')
		{
			rad->stg = 0;
			rad->drt = 0;
		}
		else
		{
			car = readchar();
			rad->stg = citesteArbore();
			if (car != ',')
			{
				rad->drt = 0;
			}
			else
			{
				car = readchar();
				rad->drt = citesteArbore();
			}
			if (car != ')')  eroare();
			car = readchar();
		}
	}
	return rad;
}

Nod* creareArbore()
{
	printf("Exemplu: A(B(-,C),D(E(F,-),G(H,-)))\n");
	printf("Introduceti arborele:");
	car = readchar();
	return citesteArbore();
}

void inordine(Nod *p)
{
	if(p)
	{
		
		inordine(p->stg);
		cout<<p->data<<' ';
		inordine(p->drt);
	}

}

void postordine(Nod *p)
{
	if(p)
	{
		postordine(p->stg);
		postordine(p->drt);
		cout<<p->data<<' ';
	}
	
}


int isEmpty(Queue q)
{
	return (q.head==0 && q.tail==0);
}

void put(Queue &q,Nod *nod)
{
    Element *p=new Element;

    if(p==NULL)
    {
        cout<<"Memorie insuficienta \n";
        exit(EXIT_FAILURE);
    }

    p->nod=nod;
    p->next=0;
    if(isEmpty(q))
    {
        q.tail=p;
        q.head=p;
    }
    else
    {
        q.tail->next=p;
        q.tail=p;
    }
}
Nod *get(Queue &q)
{
    Nod *extragere;
	Element *p;
    //!1 element
    if(isEmpty(q))
    {
        cout<<"Coada este goala\n";
        exit(EXIT_FAILURE);
    } 

    extragere=q.head->nod;
    p=q.head;
    if(q.tail!=q.head)
    {
        q.head=q.head->next;
    }
    else   //am un singur element
    {
        q.tail=0;
        q.head=0;
    }

    delete p;

    return extragere;
}

void afisare_pe_niveluri(Nod *root)
{
	int x,level=1,nr=1;
	Nod *p;
	Queue q;
	
	if(root)
	{
		q.head=q.tail=0;
		put(q,root);	
		while(!isEmpty(q))
		{
			
			p=get(q);
			if(pow(2,level-1)==nr)
			{
				
				cout<<endl;
				cout<<"Nivelul "<<level<<": ";
				level++;
			}
			nr++;
			cout<<p->data<<' ';
			if(p->stg)
			{
				put(q,p->stg);
			}
			if(p->drt)
			{
				put(q,p->drt);
			}
		}
	}

}

int depth(Nod *root)
{
	int a=1,b=1;
	if(!root)
	{
		return 0;
	}
	a=a+depth(root->stg);
	b=b+depth(root->drt);

	return (a<b ? b:a);
}



void noduri_interne(Nod *root,int &nr)
{
	int ok=0;
	if(root)
	{
		if(root->drt)
		{
			ok=1;
			noduri_interne(root->drt,nr);
		}
		if(root->stg)
		{
			ok=1;
			noduri_interne(root->stg,nr);
		}
		if(ok==1)
		{
			nr++;
		}
	}
}

int nr_frunze(Nod *root)
{
	if(root==0)
	{
		return 0;
	}

	if(root->stg==0 && root->drt==0)
	{
		return 1;
	}

	return nr_frunze(root->drt)+nr_frunze(root->stg);
}



char cautare_max(Nod *root)
{
	char a,b,mx;
	if(root==0)
	{
		return 0;
	}

	a=cautare_max(root->stg);
	b=cautare_max(root->drt);

	if(root->data >a && root->data >b)
	{
		cout<<root->data<<' ';
		return root->data;
	}

	return max(root->data,max(a,b));
}

char st_vs_dr(Nod *root)
{
	char a,b,mx;
	if(root==0)
	{
		return 0;
	}

	a=st_vs_dr(root->stg);
	b=st_vs_dr(root->drt);

	if(a<=b)
	{
		cout<<root->data<<' ';
		return a;
	}

	return min(a,b);
}

