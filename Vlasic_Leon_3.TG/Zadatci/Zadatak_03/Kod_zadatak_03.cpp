//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 *  Name:         Zadatak 3 - klase ucenici
 *  Author:       Leon Vlašić
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;


class Ucenik
{
public:
	string ime;
	string prezime;
	int ocjena[5];
	double prosjek;
	bool pozitivne;

	Ucenik();
	Ucenik(int);

	void Podatci()
	{
		cout << "Ime ucenika: ";
		cin >> ime;
		cout << "Prezime ucenika: ";
		cin >> prezime;
		for (int i = 0; i < 5; i++)
		{
			cout << i + 1 << ". ocjena: ";
			cin >> ocjena[i];
			if (ocjena[i]<1 || ocjena[i] > 5)
			{
				cout << "Nevaljana ocjena!!!\n\n";
				exit(1);
			}
		}
		cout << "\n\n";
	};
	bool Pozitiva()
	{
		for (int i = 0; i < 5; i++)
		{
			if (ocjena[i] < 2)
			{
				pozitivne = false;
				return pozitivne;
			}
			else if (ocjena[i] >= 2 && i == 4)
			{
				pozitivne = true;
				return pozitivne;
			}
		}
	};

	double Prosjek()
	{
		double zbroj_ocjena = 0;
		int broj_ocjena = 0;
		prosjek = 0;
		for (int i = 0; i < 5; i++)
		{
			zbroj_ocjena = zbroj_ocjena + ocjena[i];
			broj_ocjena++;
		}
		prosijek = zbroj_ocjena / broj_ocjena;
		return prosjek;
	};
};

Ucenik::Ucenik() {}

Ucenik::Ucenik(int x)
{
	if (x == 1)
	{
		ime = "Lanci";
		prezime = "Bananci";
		for (int i = 0; i < 5; i++)
		{
			ocjena[i] = 4;
		}
	}
	else if (x == 2)
	{
		ime = "Ines";
		prezime = "Tomik";
		for (int i = 0; i < 5; i++)
		{
			ocjena[i] = 3;
		}
	}

};


int main()
{
	Ucenik ucenik[5];
	double prosjek_1, prosjek_2, prosjek_3;
	Ucenik temp;
	string Najbolji_ucenik;
	double Najbolji_prosjek = 0;


	for (int i = 0; i < 3; i++)
		ucenik[i].Podatci();

	ucenik[3] = Ucenik(1);
	ucenik[4] = Ucenik(2);

	for (int i = 0; i < 5; i++)
	{
		if (ucenik[i].Pozitiva())
		{
			cout << "\n" << ucenik[i].ime << " " << ucenik[i].prezime;
			cout << "; Prosjek: " << ucenik[i].Prosjek() << endl;

			if (Najbolji_prosjek < ucenik[i].Prosjek())
			{
				Najbolji_prosjek = ucenik[i].Prosjek();
				Najbolji_ucenik = ucenik[i].ime + " " + ucenik[i].prezime;
			}
		}
		else
		{
			cout << "\n" << ucenik[i].ime << " " << ucenik[i].prezime;
			cout << "; Uceniku nisu sve ocjene pozitivne.";
		}
	}
	cout << "\n\nNajbolji ucenik je " << Najbolji_ucenik << " s prosjekom ocjena " << Najbolji_prosjek << "\n\n\n";


	system("pause");
	return 0;
}