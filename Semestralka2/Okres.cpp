#include "Okres.h"


Okres::Okres(int pIdKraja, string pNazovKraja, int pIdOkresu, string pNazovOkresu, int pPocZapVolicov, int pPocVydObalok, double pUcastVolicov, int pPocOdoObalok, int pPocPlatHlasov, int pPocZapVolicov2, int pPocVydObalok2, double pUcastVolicov2, int pPocOdoObalok2, int pPocPlatHlasov2)
{
	aIdKraja = pIdKraja;
	aNazovKraja = pNazovKraja;
	aIdOkresu = pIdOkresu;
	aNazovOkresu = pNazovOkresu;
	aPocZapVolicov = pPocZapVolicov;
	aPocVydObalok = pPocVydObalok;
	aUcastVolicov = pUcastVolicov;
	aPocOdoObalok = pPocOdoObalok;
	aPocZapVolicov2 = pPocZapVolicov2;
	aPocVydObalok2 = pPocVydObalok2;
	aUcastVolicov2 = pUcastVolicov2;
	aPocOdoObalok2 = pPocOdoObalok2;
	aPocPlatHlasov = pPocPlatHlasov;
	aPocPlatHlasov2 = pPocPlatHlasov2;
}

void Okres::pridatKandidata1(int pPoradie, string pMeno, string pPriezvisko, int pPocPlHlasov)
{
	kandidati1->insert(pMeno + " " + pPriezvisko, new Kandidat(pPoradie, pMeno, pPriezvisko, pPocPlHlasov));
}

void Okres::pridatKandidata2(int pPoradie, string pMeno, string pPriezvisko, int pPocPlHlasov)
{
	kandidati2->insert(pMeno + " " + pPriezvisko, new Kandidat(pPoradie, pMeno, pPriezvisko, pPocPlHlasov));
}

int Okres::getPocVydObalok(int kolo)
{
	if (kolo == 1)
	{
		return aPocVydObalok;
	}
	else if (kolo == 2)
	{
		return aPocVydObalok2;
	}
	else
	{
		return aPocVydObalok + aPocVydObalok2;
	}
}

int Okres::getPocOdoObalok(int kolo)
{
	if (kolo == 1)
	{
		return aPocOdoObalok;
	}
	else if (kolo == 2)
	{
		return aPocOdoObalok2;
	}
	else
	{
		return aPocOdoObalok + aPocOdoObalok2;
	}
}

int Okres::getPocOdoHlasov(int kolo, Kandidat & k)
{
	if (kolo == 1)
	{
		if (kandidati1->containsKey(k.getMenoAPriezvisko()))
		{
			return (*kandidati1)[k.getMenoAPriezvisko()]->getPocPlHlasov();
		}
	}
	else if (kolo == 2)
	{
		if (kandidati2->containsKey(k.getMenoAPriezvisko()))
		{
			return (*kandidati2)[k.getMenoAPriezvisko()]->getPocPlHlasov();
		}
	}
	else
	{
		if (kandidati1->containsKey(k.getMenoAPriezvisko()) && kandidati2->containsKey(k.getMenoAPriezvisko()))
		{
			return (*kandidati2)[k.getMenoAPriezvisko()]->getPocPlHlasov() + (*kandidati1)[k.getMenoAPriezvisko()]->getPocPlHlasov();
		}
	}
}

Okres::~Okres()
{
	for (auto k : (*kandidati1))
	{
		delete k->accessData();
	}
	delete kandidati1;
	for (auto k : (*kandidati2))
	{
		delete k->accessData();
	}
	delete kandidati2;
}
