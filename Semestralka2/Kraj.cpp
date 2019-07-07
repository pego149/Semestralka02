#include "Kraj.h"


Kraj::Kraj(int pIdKraja, string pNazovKraja, int pPocZapVolicov, int pPocVydObalok, double pUcastVolicov, int pPocOdoObalok, int pPocPlatHlasov, int pPocZapVolicov2, int pPocVydObalok2, double pUcastVolicov2, int pPocOdoObalok2, int pPocPlatHlasov2)
{
	aIdKraja = pIdKraja;
	aNazovKraja = pNazovKraja;
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

void Kraj::pridatKandidata1(int pPoradie, string pMeno, string pPriezvisko, int pPocPlHlasov)
{
	kandidati1->insert(pMeno + " " + pPriezvisko, new Kandidat(pPoradie, pMeno, pPriezvisko, pPocPlHlasov));
}

void Kraj::pridatKandidata2(int pPoradie, string pMeno, string pPriezvisko, int pPocPlHlasov)
{
	kandidati2->insert(pMeno + " " + pPriezvisko, new Kandidat(pPoradie, pMeno, pPriezvisko, pPocPlHlasov));
}

int Kraj::getPocVydObalok(int kolo)
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

int Kraj::getPocOdoObalok(int kolo)
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

int Kraj::getPocOdoHlasov(int kolo, Kandidat & k)
{
	if (kolo == 1)
	{
		if (kandidati1->containsKey(k.getMeno() + " " + k.getPriezvisko()))
		{
			return (*kandidati1)[k.getMeno() + " " + k.getPriezvisko()]->getPocPlHlasov();
		}
	}
	else if (kolo == 2)
	{
		if (kandidati2->containsKey(k.getMeno() + " " + k.getPriezvisko()))
		{
			return (*kandidati2)[k.getMeno() + " " + k.getPriezvisko()]->getPocPlHlasov();
		}
	}
	else
	{
		if (kandidati1->containsKey(k.getMeno() + " " + k.getPriezvisko()) && kandidati2->containsKey(k.getMeno() + " " + k.getPriezvisko()))
		{
			return (*kandidati2)[k.getMeno() + " " + k.getPriezvisko()]->getPocPlHlasov() + (*kandidati1)[k.getMeno() + " " + k.getPriezvisko()]->getPocPlHlasov();
		}
	}
}

Kraj::~Kraj()
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
