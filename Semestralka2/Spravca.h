#pragma once
#include "structures/table/sorted_sequence_table.h"
#include "structures/table/unsorted_sequence_table.h"
#include "structures/table/sorting/heap_sort.h"
#include "structures/table/sorting/shuffle.h"
#include "Kraj.h"
#include "Okres.h"
#include "Obec.h"
#include "Kriterium.h"
#include "Filter.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;
class Spravca
{
	structures::SortedSequenceTable<string, Kraj*>* kraje = new structures::SortedSequenceTable<string, Kraj*>();
	structures::SortedSequenceTable<string, Okres*>* okresy = new structures::SortedSequenceTable<string, Okres*>();
	structures::SortedSequenceTable<string, Obec*>* obce = new structures::SortedSequenceTable<string, Obec*>();
	structures::SortedSequenceTable<string, Area*>* vyfiltrovane = new structures::SortedSequenceTable<string, Area*>();
	bool aAktivne = true;
public:
	Spravca();
	void nacitaj();
	void nacitajKraje(string pMenoSuboruKraj, string menoSuboruKrajKandidati, string pMenoSuboruKraj2, string menoSuboruKrajKandidati2);
	void nacitajOkresy(string pMenoSuboruOkresy, string menoSuboruOkresyKandidati, string pMenoSuboruOkres2, string menoSuboruOkresKandidati2);
	void nacitajObce(string pMenoSuboruObce, string menoSuboruObceKandidati, string pMenoSuboruObec2, string menoSuboruObecKandidati2);
	bool getAktivne() { return aAktivne; }
	void koniec() { aAktivne = false; };
	void vypisInfoOJednotke();
	void zoradObcePodlaFiltra();
	void zoradObce();
	void vyfiltruj(int kolo);
	void vypisanieVysledkovKandidata(bool sort);
	void vypisanieVyberovychKriterii();
	void vytvorKoalicie();
	~Spravca();
};

