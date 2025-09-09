// Colorare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//Pentru a da calea relativ la folder-ul unde este sln
//Properties → Configuration Properties → C/C++ → General
//...calea unde este sln...\Colorare\include;%(AdditionalIncludeDirectories)
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <iostream>
using namespace std;

struct Pozitie {
	int x, y;
};


typedef Pozitie Atom;       // elementele cozii sint de tip Pozitie

struct Element{
	Atom data;
	Element *next;
};

struct Queue{
	Element *head,*tail;
};

Pozitie directii[4] = { { -1,0 },{ 0,-1 },{ 1,0 },{ 0,1 } };

void put(Queue &q, Pozitie a)
{
    Element *p=new Element;

    if(p==NULL)
    {
        cout<<"Memorie insuficienta \n";
        exit(EXIT_FAILURE);
    }

    p->data=a;
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
int isEmpty(Queue &q)
{
    return (q.tail==0 && q.head==0);
}
Atom get(Queue &q)
{
    Element *p;
    Atom a;
    //!1 element
    if(isEmpty(q))
    {
        cout<<"Coada este goala\n";
        exit(EXIT_FAILURE);
    } 

    a=q.head->data;
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

    return a;
}
int isEmpty(Queue &q)
{
    return (q.tail==0 && q.head==0);
}
cv::Mat ColoreazaDomeniu(cv::Mat in, Pozitie init, unsigned char color) {
	cv::Mat imgOut;
	in.copyTo(imgOut); //imgOut este o copie a lui in

	//dimensiunile imaginii
	int width = in.size().width;
	int height = in.size().height;

	unsigned char culoareDomeniu = in.at<unsigned char>(init.y, init.x);
	std::cout << "Color: " << (unsigned int)culoareDomeniu << "( " << init.x << ", " << init.y << ")" << std::endl;

	//...Algoritmul descris in lab in pseudocod
	//
	Queue q;
    put(q,init);
	init.x=color;
	init.y=color;

    int i;
	Atom pi,p;
	while(!isEmpty(q))
	{
		p=get(q);
		for(i=0;i<4;i++)
		{
			pi.x=p.x+directii[i].x;
			pi.y=p.y+directii[i].y;

			if(!(pi.x>width || pi.y>height))
			{
				if(pi.x==culoareDomeniu && pi.y==culoareDomeniu)
				{
					put(q,pi);
					pi.x=color;
					pi.y=color;
				}
			}
		}
	}

	//
	std::cout << "DONE!" << std::endl;
	return imgOut;
}

int main()
{
	cv::Mat imgIn = cv::imread("img.png"); //obiectul Mat contine o matrice de pixeli
	cv::cvtColor(imgIn, imgIn, CV_RGB2GRAY);
	cv::namedWindow("Input");
	cv::namedWindow("Output");

	Pozitie posInit;
	posInit.x = imgIn.size().width / 2;
	posInit.y = imgIn.size().height / 2;

	//imgIn este o imagine grayscale (fiecare pixel este reprezentat de o valoare pe 8 biti, in [0,255])
	cv::Mat imgOut = ColoreazaDomeniu(imgIn, posInit, (unsigned char)255);

	//afisarea imaginilor
	cv::imshow("Input", imgIn);
	cv::imshow("Output", imgOut);
	cv::waitKey();

	return 0;
}

