#include <iostream>
#include "functii.h"
#include <string.h>
using namespace std;

int main(void)
{
    char s[100],polonez[100]={0};
    int i=0;
    cout<<"Dati expresia \n >>";
    cin>>s;
    conversie(s,polonez);

    cout<<"Forma poloneza este \n";
    cout<<polonez;
    cout<<endl;
    cout<<"Rezultatul expresiei este \n>> "<<evaluare(polonez)<<endl;


    return 0;
}