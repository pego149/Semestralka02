#pragma once
#include <iostream>
#include "structures/table/sorted_sequence_table.h"
#include "Kandidat.h"
#include "Area.h"

class Okres : public Area
{
	structures::SortedSequenceTable<string, Kandidat*>* kandidati1 = new structures::SortedSequenceTable<string, Kandidat*>();
	structures::SortedSequenceTable<string, Kandidat*>* kandidati2 = new structures::SortedSequenceTable<string, Kandidat*>();
	int aIdKraja;
	string aNazovKraja;
	int aIdOkresu;
	string aNazovOkresu;
	int aPocZapVolicov;
	int aPocVydObalok;
	double aUcastVolicov;
	int aPocOdoObalok;
	int aPocZapVolicov2;
	int aPocVydObalok2;
	double aUcastVolicov2;
	int aPocOdoObalok2;
	int aPocPlatHlasov;
	int aPocPlatHlasov2;
public:
	Okres(int pIdKraja, string pNazovKraja, int pIdOkresu, string pNazovOkresu, int pPocZapVolicov, int pPocVydObalok, double pUcastVolicov, int pPocOdoObalok, int pPocPlatHlasov,
		int pPocZapVolicov2, int pPocVydObalok2, double pUcastVolicov2, int pPocOdoObalok2, int pPocPlatHlasov2);
	void pridatKandidata1(int pPoradie, string pMeno, string pPriezvisko, int pPocPlHlasov);
	void pridatKandidata2(int pPoradie, string pMeno, string pPriezvisko, int pPocPlHlasov);
	string getNazov() override { return aNazovOkresu; }
	string getNazovKraja() override { return aNazovKraja + " <- "; }
	string getNazovOkresu() override { return ""; }
	int getPocZapVolicov(int kolo) override { return kolo == 1 ? aPocZapVolicov : aPocZapVolicov2; }
	int getPocPlatHlasov(int kolo) override { return kolo == 1 ? aPocPlatHlasov : aPocPlatHlasov2; }
	int getPocVydObalok(int kolo) override;
	int getPocOdoObalok(int kolo) override;
	structures::SortedSequenceTable<string, Kandidat*> getKandidati(int kolo) override { return kolo == 1 ? *kandidati1 : *kandidati2; }
	double getUcastVolicov(int kolo) override { return kolo == 1 ? aUcastVolicov : aUcastVolicov2; }
	int getPocOdoHlasov(int kolo, Kandidat& k) override;
	int getId() override { return aIdOkresu; }
	~Okres();
};

