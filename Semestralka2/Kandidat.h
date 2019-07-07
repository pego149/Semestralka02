#pragma once
#include <iostream>

using namespace std;
class Kandidat
{
	int aPoradie;
	string aMeno;
	string aPriezvisko;
	int aPocPlHlasov;
public:
	Kandidat(int pPoradie, string pMeno, string pPriezvisko, int pPocPlHlasov);
	int getPoradie() { return aPoradie; }
	string getMeno() { return aMeno; }
	string getPriezvisko() { return aPriezvisko; }
	string getMenoAPriezvisko() { return aMeno + " " + aPriezvisko; }
	int getPocPlHlasov() { return aPocPlHlasov; }
	~Kandidat();
};

