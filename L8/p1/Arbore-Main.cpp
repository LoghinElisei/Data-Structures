#include <iostream>
#include "Arbore.h"

using namespace std;

int main()
{
	Nod *root = creareArbore();
	int nr=0;
	cout<<"Inordine\n";
	inordine(root);
	
	cout<<endl<<"Postordine\n";
	postordine(root);
	cout<<endl<<endl;

	cout<<"\t*** Afisare pe niveluri ***";
	afisare_pe_niveluri(root);
	cout<<endl<<endl;

	cout<<"Adancimea arborelui este : "<<depth(root)<<endl<<endl;
	
	cout<<"Nr. de noduri interne este : ";
	noduri_interne(root,nr);
	cout<<nr<<endl<<endl;

	cout<<"Nr. de frunze este : "<<nr_frunze(root)<<endl<<endl;

	cout<<"Noduri cu valoarea mai mare decat toate val. subarborilor desc.\n>> ";
	cautare_max(root);
	cout<<endl<<endl;

	cout<<"Toate nodurile pentru care toate valorile conținute în subarborele stâng sunt mai mici decât toate valorile conținute în subarborele drept\n>> ";
	st_vs_dr(root);
	cout<<endl<<endl;
	return 0;
}