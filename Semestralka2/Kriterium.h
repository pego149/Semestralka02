#pragma once
#include <iostream>
#include "Area.h"

using namespace std;
template<typename T, typename O>
class Kriterium
{
	public: virtual T over(O& o) = 0;
};

template<typename O>
class KriteriumNazov : public Kriterium<string, O> 
{
	public: string over(O& o) override { return o->getNazov(); }
};

template<typename O>
class KriteriumPrislusnost : public Kriterium<bool, O> 
{
private: Area* uc = nullptr;
public: 
	bool over(O& o) override
	{
		if (uc->getNazov() == o->getNazovOkresu() || uc->getNazov() == o->getNazovKraja())
			return true;
		return false;
	}
	void set(Area& in) { uc = &in; }
};

template<typename O>
class KriteriumVolici : public Kriterium<int, O> {
private: int kolo = 0;
public: 
	int over(O& o) override { return o->getPocZapVolicov(kolo);	}
	void set(const int& in) { kolo = in; }
};

template<typename O>
class KriteriumVydaneObalky : public Kriterium<int, O> {
	private: int uc = 0;
	public: 
	int over(O& o) override { return o->getPocVydObalok(uc); }
	void set(const int& in) { uc = in; }
};

template<typename O>
class KriteriumUcast : public Kriterium<double, O> {
private: int uc = 0;
public:
	double over(O& o) override { return o->getUcastVolicov(uc); }
	void set(const int& in) { uc = in; }
};

template<typename O>
class KriteriumOdovzdaneObalky : public Kriterium<int, O> {
private: int uc = 0;
public:
	int over(O& o) override { return o->getPocOdoObalok(uc); }
	void set(const int& in) { uc = in; }
};

template<typename O>
class KriteriumOdovzdaneHlasy : public Kriterium<int, O> {
private: int uc = 0;
		 Kandidat* k = nullptr;
public:
	int over(O& o) override { return o->getPocOdoHlasov(uc, *k); }
	void setKolo(const int& in) { uc = in; }
	void setKandidat(Kandidat& in) { k = &in; }
};

template<typename O>
class KriteriumMeno : public Kriterium<string, O> {
public: string over(O& o) override { return o->getMenoAPriezvisko(); }
};

template<typename O>
class KriteriumZiskaneHlasy : public Kriterium<int, O> {
private: int uc = 0;
		 Area* z = nullptr;
public:
	int over(O& o) override { return z->getPocOdoHlasov(uc, o); }
	void setKolo(const int& in) { uc = in; }
	void setArea(const Area& in) { z = &in; }
};

template<typename O>
class KriteriumNajviacHlasov : public Kriterium<string, O> {
private: int uc = 0;
		 int hlasy = 0;
public:
	string over(O& o) override {
		structures::SortedSequenceTable<string, Kandidat*>* kandidati = new structures::SortedSequenceTable<string, Kandidat*>();
		*kandidati = o->getKandidati(uc);
		string meno;
		hlasy = 0;
		for (auto k : (*kandidati))
		{
			if (k->accessData()->getPocPlHlasov() > hlasy)
			{
				hlasy = k->accessData()->getPocPlHlasov();
				meno = k->getKey();
			}
		}
		delete kandidati;
		return meno;
	}
	void setKolo(const int& in) { uc = in; }
	int getHlasy() { return hlasy; }
};

template<typename O>
class KriteriumNajmenejHlasov : public Kriterium<string, O> {
private: int uc = 0;
		 int hlasy;
public:
	string over(O& o) override {
		structures::SortedSequenceTable<string, Kandidat*>* kandidati = new structures::SortedSequenceTable<string, Kandidat*>();
		*kandidati = o->getKandidati(uc);
		string meno;
		hlasy = 5000000;
		for (auto k : (*kandidati))
		{
			if (k->accessData()->getPocPlHlasov() < hlasy)
			{
				hlasy = k->accessData()->getPocPlHlasov();
				meno = k->getKey();
			}
		}
		delete kandidati;
		return meno;
	}
	void setKolo(const int& in) { uc = in; }
	int getHlasy() { return hlasy; }
};

template<typename O>
class KriteriumNajmensiRozdiel : public Kriterium<string, O> {
private:int rozdiel;
public:
	string over(O& o) override {
		structures::SortedSequenceTable<string, Kandidat*>* kandidati1 = new structures::SortedSequenceTable<string, Kandidat*>();
		structures::SortedSequenceTable<string, Kandidat*>* kandidati2 = new structures::SortedSequenceTable<string, Kandidat*>();
		*kandidati1 = o->getKandidati(1);
		*kandidati2 = o->getKandidati(2);
		int zc = abs((*kandidati1)["Zuzana Caputova"]->getPocPlHlasov() - (*kandidati2)["Zuzana Caputova"]->getPocPlHlasov());
		int ms = abs((*kandidati1)["Maros Sefcovic"]->getPocPlHlasov() - (*kandidati2)["Maros Sefcovic"]->getPocPlHlasov());
		if (zc < ms)
		{
			delete kandidati1;
			delete kandidati2;
			rozdiel = zc;
			return "Zuzana Caputova";
		}
		else
		{

			delete kandidati1;
			delete kandidati2;
			rozdiel = ms;
			return "Maros Sefcovic";
		}
	}
	int getRozdiel() { return rozdiel; }
};

template<typename O>
class KriteriumHlasyKoalicie : public Kriterium<int, O> {
private:structures::ArrayList<char*> *koalicia = new structures::ArrayList<char*>();
		int kolo = 1;
public:
	int over(O& o) override {
		structures::SortedSequenceTable<string, Kandidat*>* kandidati = new structures::SortedSequenceTable<string, Kandidat*>();
		*kandidati = o->getKandidati(kolo);
		int hlasy = 0;
		for (char* k : (*koalicia))
		{
			hlasy += (*kandidati)[k]->getPocPlHlasov();
		}
		delete kandidati;
		return hlasy;
	}
	~KriteriumHlasyKoalicie() { 
		for (auto k : (*koalicia))
			delete k;
		delete koalicia; 
	}
	void pridaj(string k) { koalicia->add(strdup(k.c_str())); }
	string getKandidati() 
	{
		string s;
		for (char* k : (*koalicia))
		{
			s += k;
			s += " ";
		}
		s += ":";
		return s;
	}
};