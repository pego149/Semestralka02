#pragma once
#include <iostream>
#include "Kandidat.h"
#include "structures/table/sorted_sequence_table.h"

using namespace std;
class Area
{
public: virtual string getNazov() = 0;
		virtual string getNazovKraja() = 0;
		virtual string getNazovOkresu() = 0;
		virtual int getPocZapVolicov(int kolo) = 0;
		virtual int getPocVydObalok(int kolo) = 0;
		virtual structures::SortedSequenceTable<string, Kandidat*> getKandidati(int kolo) = 0;
		virtual int getPocOdoObalok(int kolo) = 0;
		virtual int getPocPlatHlasov(int kolo) = 0;
		virtual double getUcastVolicov(int kolo) = 0;
		virtual int getPocOdoHlasov(int kolo, Kandidat& k) = 0;
		virtual int getId() = 0;
};