#include "Spravca.h"


Spravca::Spravca()
{
	nacitaj();
}

void Spravca::nacitaj()
{
	clock_t time1 = clock();
	nacitajKraje("kolo1/PRE_2019_KOLO1_tab02a.csv", "kolo1/PRE_2019_KOLO1_tab03b.csv", "kolo2/PRE_2019_KOLO2_tab02a.csv", "kolo2/PRE_2019_KOLO2_tab03b.csv");
	clock_t time2 = clock();
	cout << "[LOG] Nacitane kraje " << double(time2 - time1) << "ms" << endl;
	nacitajOkresy("kolo1/PRE_2019_KOLO1_tab02c.csv", "kolo1/PRE_2019_KOLO1_tab03d.csv", "kolo2/PRE_2019_KOLO2_tab02c.csv", "kolo2/PRE_2019_KOLO2_tab03d.csv");
	time1 = clock();
	cout << "[LOG] Nacitane okresy " << double(time1 - time2) << "ms" << endl;
	nacitajObce("kolo1/PRE_2019_KOLO1_tab02d.csv", "kolo1/PRE_2019_KOLO1_tab03e.csv", "kolo2/PRE_2019_KOLO2_tab02d.csv", "kolo2/PRE_2019_KOLO2_tab03e.csv");
	time2 = clock();
	cout << "[LOG] Nacitane obce " << double(time2 - time1) << "ms" << endl;
}

void Spravca::nacitajKraje(string pMenoSuboruKraj, string menoSuboruKrajKandidati, string pMenoSuboruKraj2, string menoSuboruKrajKandidati2)
{
	ifstream file(pMenoSuboruKraj);
	ifstream file1(pMenoSuboruKraj2);
	string value;
	int IdKraja;
	string NazovKraja;
	int PocZapVolicov;
	int PocVydObalok;
	double UcastVolicov;
	int PocOdoObalok;
	int PocZapVolicov2;
	int PocVydObalok2;
	double UcastVolicov2;
	int PocOdoObalok2;
	int PocPlatHlasov;
	int PocPlatHlasov2;
	while (file.good() && file1.good())
	{
		getline(file, value, ';');
		IdKraja = atoi(value.c_str());
		getline(file, value, ';');
		NazovKraja = value;
		getline(file, value, ';');
		PocZapVolicov = atoi(value.c_str());
		getline(file, value, ';');
		PocVydObalok = atoi(value.c_str());
		getline(file, value, ';');
		UcastVolicov = atof(value.c_str());
		getline(file, value, ';');
		PocOdoObalok = atoi(value.c_str());
		getline(file, value, '\n');
		PocPlatHlasov = atoi(value.c_str());

		getline(file1, value, ';');
		PocZapVolicov2 = atoi(value.c_str());
		getline(file1, value, ';');
		PocVydObalok2 = atoi(value.c_str());
		getline(file1, value, ';');
		UcastVolicov2 = atof(value.c_str());
		getline(file1, value, ';');
		PocOdoObalok2 = atoi(value.c_str());
		getline(file1, value, '\n');
		PocPlatHlasov2 = atoi(value.c_str());

		kraje->insert(NazovKraja, new Kraj(IdKraja, NazovKraja, PocZapVolicov, PocVydObalok, UcastVolicov, PocOdoObalok, PocPlatHlasov, PocZapVolicov2, PocVydObalok2, UcastVolicov2, PocOdoObalok2, PocPlatHlasov2));
	}
	ifstream file2(menoSuboruKrajKandidati);
	int poradie;
	string meno;
	string priezvisko;
	int pocPlHlasov;
	while (file2.good())
	{
		getline(file2, value, ';');
		IdKraja = atoi(value.c_str());
		getline(file2, value, ';');
		NazovKraja = value;
		getline(file2, value, ';');
		poradie = atoi(value.c_str());
		getline(file2, value, ';');
		meno = value;
		getline(file2, value, ';');
		priezvisko = value;
		getline(file2, value, '\n');
		pocPlHlasov = atoi(value.c_str());
		(*kraje)[NazovKraja]->pridatKandidata1(poradie, meno, priezvisko, pocPlHlasov);
	}

	ifstream file3(menoSuboruKrajKandidati2);
	while (file3.good())
	{
		getline(file3, value, ';');
		NazovKraja = value;
		getline(file3, value, ';');
		poradie = atoi(value.c_str());
		getline(file3, value, ';');
		meno = value;
		getline(file3, value, ';');
		priezvisko = value;
		getline(file3, value, '\n');
		pocPlHlasov = atoi(value.c_str());
		(*kraje)[NazovKraja]->pridatKandidata2(poradie, meno, priezvisko, pocPlHlasov);
	}
}

void Spravca::nacitajOkresy(string pMenoSuboruOkresy, string menoSuboruOkresyKandidati, string pMenoSuboruOkres2, string menoSuboruOkresKandidati2)
{
	ifstream file(pMenoSuboruOkresy);
	ifstream file1(pMenoSuboruOkres2);
	string value;
	int IdKraja;
	string NazovKraja;
	int IdOkresu;
	string NazovOkresu;
	int PocZapVolicov;
	int PocVydObalok;
	double UcastVolicov;
	int PocOdoObalok;
	int PocZapVolicov2;
	int PocVydObalok2;
	double UcastVolicov2;
	int PocOdoObalok2;
	int PocPlatHlasov;
	int PocPlatHlasov2;
	while (file.good() && file1.good())
	{
		getline(file, value, ';');
		IdKraja = atoi(value.c_str());
		getline(file, value, ';');
		NazovKraja = value;
		getline(file, value, ';');
		IdOkresu = atoi(value.c_str());
		getline(file, value, ';');
		NazovOkresu = value;
		getline(file, value, ';');
		PocZapVolicov = atoi(value.c_str());
		getline(file, value, ';');
		PocVydObalok = atoi(value.c_str());
		getline(file, value, ';');
		UcastVolicov = atof(value.c_str());
		getline(file, value, ';');
		PocOdoObalok = atoi(value.c_str());
		getline(file, value, '\n');
		PocPlatHlasov = atoi(value.c_str());

		getline(file1, value, ';');
		PocZapVolicov2 = atoi(value.c_str());
		getline(file1, value, ';');
		PocVydObalok2 = atoi(value.c_str());
		getline(file1, value, ';');
		UcastVolicov2 = atof(value.c_str());
		getline(file1, value, ';');
		PocOdoObalok2 = atoi(value.c_str());
		getline(file1, value, '\n');
		PocPlatHlasov2 = atoi(value.c_str());
		okresy->insert(NazovOkresu, new Okres(IdKraja, NazovKraja, IdOkresu, NazovOkresu, PocZapVolicov, PocVydObalok, UcastVolicov, PocOdoObalok, PocPlatHlasov, PocZapVolicov2, PocVydObalok2, UcastVolicov2, PocOdoObalok2, PocPlatHlasov2));

	}
	ifstream file2(menoSuboruOkresyKandidati);
	int poradie;
	string meno;
	string priezvisko;
	int pocPlHlasov;
	while (file2.good())
	{
		getline(file2, value, ';');
		IdKraja = atoi(value.c_str());
		getline(file2, value, ';');
		NazovKraja = value;
		getline(file2, value, ';');
		IdOkresu = atoi(value.c_str());
		getline(file2, value, ';');
		NazovOkresu = value;
		getline(file2, value, ';');
		poradie = atoi(value.c_str());
		getline(file2, value, ';');
		meno = value;
		getline(file2, value, ';');
		priezvisko = value;
		getline(file2, value, '\n');
		pocPlHlasov = atoi(value.c_str());
		(*okresy)[NazovOkresu]->pridatKandidata1(poradie, meno, priezvisko, pocPlHlasov);
	}

	ifstream file3(menoSuboruOkresKandidati2);
	while (file3.good())
	{
		getline(file3, value, ';');
		NazovOkresu = value;
		getline(file3, value, ';');
		poradie = atoi(value.c_str());
		getline(file3, value, ';');
		meno = value;
		getline(file3, value, ';');
		priezvisko = value;
		getline(file3, value, '\n');
		pocPlHlasov = atoi(value.c_str());
		(*okresy)[NazovOkresu]->pridatKandidata2(poradie, meno, priezvisko, pocPlHlasov);
	}
}

void Spravca::nacitajObce(string pMenoSuboruObce, string menoSuboruObceKandidati, string pMenoSuboruObec2, string menoSuboruObecKandidati2)
{
	ifstream file(pMenoSuboruObce);
	ifstream file1(pMenoSuboruObec2);
	string value;
	int IdKraja;
	string NazovKraja;
	int IdOkresu;
	string NazovOkresu;
	int IdObce;
	string NazovObce;
	int PocZapVolicov;
	int PocVydObalok;
	double UcastVolicov;
	int PocOdoObalok;
	int PocZapVolicov2;
	int PocVydObalok2;
	double UcastVolicov2;
	int PocOdoObalok2;
	int PocPlatHlasov;
	int PocPlatHlasov2;
	while (file.good() && file1.good())
	{
		getline(file, value, ';');
		IdKraja = atoi(value.c_str());
		getline(file, value, ';');
		NazovKraja = value;
		getline(file, value, ';');
		IdOkresu = atoi(value.c_str());
		getline(file, value, ';');
		NazovOkresu = value;
		getline(file, value, ';');
		IdObce = atoi(value.c_str());
		getline(file, value, ';');
		NazovObce = value;
		getline(file, value, ';');
		PocZapVolicov = atoi(value.c_str());
		getline(file, value, ';');
		PocVydObalok = atoi(value.c_str());
		getline(file, value, ';');
		UcastVolicov = atof(value.c_str());
		getline(file, value, ';');
		PocOdoObalok = atoi(value.c_str());
		getline(file, value, '\n');
		PocPlatHlasov = atoi(value.c_str());

		getline(file1, value, ';');
		PocZapVolicov2 = atoi(value.c_str());
		getline(file1, value, ';');
		PocVydObalok2 = atoi(value.c_str());
		getline(file1, value, ';');
		UcastVolicov2 = atof(value.c_str());
		getline(file1, value, ';');
		PocOdoObalok2 = atoi(value.c_str());
		getline(file1, value, '\n');
		PocPlatHlasov2 = atoi(value.c_str());
		obce->insert(NazovObce, new Obec(IdKraja, NazovKraja, IdOkresu, NazovOkresu, IdObce, NazovObce, PocZapVolicov, PocVydObalok, UcastVolicov, PocOdoObalok, PocPlatHlasov, PocZapVolicov2, PocVydObalok2, UcastVolicov2, PocOdoObalok2, PocPlatHlasov2));
	}
	ifstream file2(menoSuboruObceKandidati);
	int poradie;
	string meno;
	string priezvisko;
	int pocPlHlasov;
	while (file2.good())
	{
		getline(file2, value, ';');
		IdKraja = atoi(value.c_str());
		getline(file2, value, ';');
		NazovKraja = value;
		getline(file2, value, ';');
		IdOkresu = atoi(value.c_str());
		getline(file2, value, ';');
		NazovOkresu = value;
		getline(file2, value, ';');
		IdObce = atoi(value.c_str());
		getline(file2, value, ';');
		NazovObce = value;
		getline(file2, value, ';');
		poradie = atoi(value.c_str());
		getline(file2, value, ';');
		meno = value;
		getline(file2, value, ';');
		priezvisko = value;
		getline(file2, value, '\n');
		pocPlHlasov = atoi(value.c_str());
		(*obce)[NazovObce]->pridatKandidata1(poradie, meno, priezvisko, pocPlHlasov);
	}

	ifstream file3(menoSuboruObecKandidati2);
	while (file3.good())
	{
		getline(file3, value, ';');
		NazovObce = value;
		getline(file3, value, ';');
		poradie = atoi(value.c_str());
		getline(file3, value, ';');
		meno = value;
		getline(file3, value, ';');
		priezvisko = value;
		getline(file3, value, '\n');
		pocPlHlasov = atoi(value.c_str());
		(*obce)[NazovObce]->pridatKandidata2(poradie, meno, priezvisko, pocPlHlasov);
	}
}


void Spravca::vypisInfoOJednotke()
{
	structures::UnsortedSequenceTable<string, Area*>* filtrovane = new structures::UnsortedSequenceTable<string, Area*>();
	structures::SortedSequenceTable<string, Area*>* jednotky = new structures::SortedSequenceTable<string, Area*>();
	string vzostZost;
	string vyberFilter;
	string jednotka;
	cout << "Zadajte jednotku:" << endl;
	cout << "\t1-> Obec" << endl;
	cout << "\t2-> Okres" << endl;
	cout << "\t3-> Kraj" << endl;
	cout << "\tVolba: ";
	cin >> jednotka;
	if (jednotka == "1")
		for (auto k : (*obce))
			jednotky->insertValid(k->getKey(), k->accessData());
	else if (jednotka == "2")
		for (auto k : (*okresy)) 
			jednotky->insertValid(k->getKey(), k->accessData());
	else if (jednotka == "3")
		for (auto k : (*kraje))
			jednotky->insertValid(k->getKey(), k->accessData());
	cout << "Zadajte filter: " << endl;
	cout << "\t1-> Nazov" << endl;
	cout << "\t2-> Pocet volicov" << endl;
	cout << "\t3-> Volebna ucast" << endl;
	cout << "\tVolba: ";
	cin >> vyberFilter;
	string volbaKrit1;
	cout << "Zadajte kolo (1/2): ";
	cin >> volbaKrit1;
	if (vyberFilter == "1")
	{
		string volbaFilter1;
		FilterNazov<Area*> *filterN = new FilterNazov<Area*>;
		cout << "Zadajte nazov: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin, volbaFilter1);
		filterN->setAlfa(volbaFilter1);
		KriteriumNazov<Area*> *krN = new KriteriumNazov<Area*>;
		for (auto k : (*jednotky))
			if (filterN->over(k->accessData(), *krN))
				filtrovane->insertValid(k->getKey(), k->accessData());
		delete krN;
		delete filterN;
	}
	else if (vyberFilter == "2")
	{
		string volbaFilter1;
		string volbaFilter2;
		KriteriumVolici<Area*> *krV = new KriteriumVolici<Area*>;
		FilterVolici<Area*> *filterV = new FilterVolici<Area*>;
		cout << "Zadajte pocet volicov od: ";
		cin >> volbaFilter1;
		cout << "Zadajte pocet volicov do: ";
		cin >> volbaFilter2;
		filterV->setAlpha(atoi(volbaFilter1.c_str()));
		filterV->setBeta(atoi(volbaFilter2.c_str()));
		krV->set(atoi(volbaKrit1.c_str()));
		for (auto k : (*jednotky))
			if (filterV->over(k->accessData(), *krV))
				filtrovane->insertValid(k->getKey(), k->accessData());
		delete krV;
		delete filterV;
	}
	else if (vyberFilter == "3")
	{
		string volbaFilter1;
		string volbaFilter2;
		KriteriumUcast<Area*> *krU = new KriteriumUcast<Area*>;
		FilterUcast<Area*> *filterU = new FilterUcast<Area*>;
		cout << "Zadajte ucast v % volicov od: ";
		cin >> volbaFilter1;
		cout << "Zadajte ucast v % volicov do: ";
		cin >> volbaFilter2;
		filterU->setAlpha(atof(volbaFilter1.c_str()));
		filterU->setBeta(atof(volbaFilter2.c_str()));
		krU->set(atoi(volbaKrit1.c_str()));
		for (auto k : (*jednotky))
			if (filterU->over(k->accessData(), *krU))
				filtrovane->insertValid(k->getKey(), k->accessData());
		delete krU;
		delete filterU;
	}
	for (auto k : (*filtrovane))
	{
		cout << k->accessData()->getNazovKraja() << " ";
		cout << k->accessData()->getNazovOkresu() << " ";
		cout << k->accessData()->getNazov() << endl;
		cout << "Pocet volicov: " << k->accessData()->getPocZapVolicov(atoi(volbaKrit1.c_str()));
		cout << ", pocet vyd. obalok: " << k->accessData()->getPocVydObalok(atoi(volbaKrit1.c_str()));
		cout << ", ucast: " << k->accessData()->getUcastVolicov(atoi(volbaKrit1.c_str()));
		cout << ", pocet odo. obalok: " << k->accessData()->getPocOdoObalok(atoi(volbaKrit1.c_str()));
		cout << ", pocet plat. hlasov: " << k->accessData()->getPocPlatHlasov(atoi(volbaKrit1.c_str())) << endl << endl;
	}
	delete jednotky;
	delete filtrovane;
}

void Spravca::zoradObcePodlaFiltra()
{
	structures::UnsortedSequenceTable<string, Obec*>* filtrovane = new structures::UnsortedSequenceTable<string, Obec*>();
	structures::SortedSequenceTable<string, Obec*>* jednotky = new structures::SortedSequenceTable<string, Obec*>();
	for (auto k : (*obce))
		jednotky->insertValid(k->getKey(), k->accessData());
	string vyberKr;
	cout << "Zoradit podla: " << endl;
	cout << "\t1-> Nazov" << endl;
	cout << "\t2-> Pocet volicov" << endl;
	cout << "\t3-> Volebna ucast" << endl;
	cout << "\tVolba: ";
	cin >> vyberKr;
	string zostVzost;
	cout << "Zoradit: " << endl;
	cout << "\t1-> Zostupne" << endl;
	cout << "\t2-> Vzostupne" << endl;
	cout << "\tVolba: ";
	cin >> zostVzost;
	int iVzZost;
	if (zostVzost == "1")
		iVzZost = -1;
	else
		iVzZost = 1;
	int kolo;
	cout << "Ktore kolo: " << endl << "\t1-> 1. kolo" << endl << "\t2-> 2. kolo" << endl << "\tVolba: ";
	cin >> kolo;
	string volbaKrit1;
	string volbaFilter1;
	string volbaFilter2;
	FilterUcast<Obec*> *filterU = new FilterUcast<Obec*>;
	KriteriumUcast<Obec*> *krU = new KriteriumUcast<Obec*>;
	cout << "Zadajte ucast volicov v % od: ";
	cin >> volbaFilter1;
	cout << "Zadajte ucast volicov v % do: ";
	cin >> volbaFilter2;
	filterU->setAlpha(atof(volbaFilter1.c_str()));
	filterU->setBeta(atof(volbaFilter2.c_str()));
	krU->set(kolo);
	string prObce;
	FilterPrislusnostObce<Obec*> *filterP = new FilterPrislusnostObce<Obec*>;
	KriteriumPrislusnost<Obec*> *krP = new KriteriumPrislusnost<Obec*>;
	cout << "Zadajte okres/kraj: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, prObce);
	if (kraje->containsKey(prObce))
	{
		krP->set(*(*kraje)[prObce]);
	}
	else if (okresy->containsKey(prObce))
	{
		krP->set(*(*okresy)[prObce]);
	}
	for (auto k : (*jednotky))
		if (filterU->over(k->accessData(), *krU) && filterP->over(k->accessData(), *krP))
			filtrovane->insertValid(k->getKey(), k->accessData());
	if (vyberKr == "1")
	{
		KriteriumNazov<Obec*> *krit = new KriteriumNazov<Obec*>;
		structures::HeapSort<string, Obec*, string> *sort = new structures::HeapSort<string, Obec*, string>;
		sort->sortbetter(*filtrovane, *krit, iVzZost);
		for (auto k : (*filtrovane))
			cout << k->accessData()->getNazov() << ": " << krit->over(k->accessData()) << endl;
		delete sort;
		delete krit;
	}
	else if (vyberKr == "2")
	{
		structures::HeapSort<string, Obec*, int> *sort = new structures::HeapSort<string, Obec*, int>;
		KriteriumVolici<Obec*> *krit = new KriteriumVolici<Obec*>;
		krit->set(kolo);
		sort->sortbetter(*filtrovane, *krit, iVzZost);
		for (auto k : (*filtrovane))
			cout << k->accessData()->getNazov() << ": " << krit->over(k->accessData()) << endl;
		delete sort;
		delete krit;
	}
	else if (vyberKr == "3")
	{
		structures::HeapSort<string, Obec*, double> *sort = new structures::HeapSort<string, Obec*, double>;
		KriteriumUcast<Obec*> *krit = new KriteriumUcast<Obec*>;
		krit->set(kolo);
		sort->sortbetter(*filtrovane, *krit, iVzZost);
		for (auto k : (*filtrovane))
			cout << k->accessData()->getNazov() << ": " << krit->over(k->accessData()) << endl;
		delete sort;
		delete krit;
	}
	delete filtrovane;
	delete jednotky;
	delete filterU;
	delete filterP;
	delete krU;
	delete krP;
}

void Spravca::zoradObce()
{
	structures::UnsortedSequenceTable<string, Area*>* jednotky = new structures::UnsortedSequenceTable<string, Area*>();
	for (auto k : (*obce))
		jednotky->insertValid(k->getKey(), k->accessData());
	string vyberKr;
	string zostVzost;
	int iVzZost;
	cout << "Zoradit podla: " << endl;
	cout << "\t1-> Nazov" << endl;
	cout << "\t2-> Pocet volicov" << endl;
	cout << "\t3-> Volebna ucast" << endl;
	cout << "\tVolba: ";
	cin >> vyberKr;
	cout << "Zoradit: " << endl;
	cout << "\t1-> Zostupne" << endl;
	cout << "\t2-> Vzostupne" << endl;
	cout << "\tVolba: ";
	cin >> zostVzost;
	if (zostVzost == "1")
		iVzZost = -1;
	else
		iVzZost = 1;
	if (vyberKr == "1")
	{
		KriteriumNazov<Area*> *krit = new KriteriumNazov<Area*>;
		structures::HeapSort<string, Area*, string> *sort = new structures::HeapSort<string, Area*, string>;
		sort->sortbetter(*jednotky, *krit, iVzZost);
		for (auto k : (*jednotky))
			cout << k->accessData()->getNazov() << ": " << krit->over(k->accessData()) << endl;
		delete sort;
		delete krit;
	}
	else if (vyberKr == "2")
	{
		structures::HeapSort<string, Area*, int> *sort = new structures::HeapSort<string, Area*, int>;
		KriteriumVolici<Area*> *krit = new KriteriumVolici<Area*>;
		int kolo;
		cout << "Ktore kolo: " << endl << "\t1-> 1. kolo" << endl << "\t2-> 2. kolo" << endl << "\tVolba: ";
		cin >> kolo;
		krit->set(kolo);
		sort->sortbetter(*jednotky, *krit, iVzZost);
		for (auto k : (*jednotky))
			cout << k->accessData()->getNazov() << ": " << krit->over(k->accessData()) << endl;
		delete sort;
		delete krit;
	}
	else if (vyberKr == "3")
	{
		structures::HeapSort<string, Area*, double> *sort = new structures::HeapSort<string, Area*, double>;
		KriteriumUcast<Area*> *krit = new KriteriumUcast<Area*>;
		int kolo;
		cout << "Ktore kolo: " << endl << "\t1-> 1. kolo" << endl << "\t2-> 2. kolo" << endl << "\tVolba: ";
		cin >> kolo;
		krit->set(kolo);
		sort->sortbetter(*jednotky, *krit, iVzZost);
		for (auto k : (*jednotky))
			cout << k->accessData()->getNazov() << ": " << krit->over(k->accessData()) << endl;
		delete sort;
		delete krit;
	}
	
	delete jednotky;
	
}

void Spravca::vyfiltruj(int kolo)
{
	delete vyfiltrovane;
	vyfiltrovane = new structures::SortedSequenceTable<string, Area*>();
	structures::SortedSequenceTable<string, Area*>* jednotky = new structures::SortedSequenceTable<string, Area*>(); 
	structures::SortedSequenceTable<string, Area*>* jednotky2 = new structures::SortedSequenceTable<string, Area*>();
	string jednotka;
	cout << "Zadajte jednotku:" << endl << "\t1-> Obec" << endl << "\t2-> Okres" << endl << "\t3-> Kraj" << endl << "\tVolba: ";
	cin >> jednotka;
	if (jednotka == "1")
		for (auto k : (*obce))
			jednotky->insertValid(k->getKey(), k->accessData());
	else if (jednotka == "2")
		for (auto k : (*okresy))
			jednotky->insertValid(k->getKey(), k->accessData());
	else if (jednotka == "3")
		for (auto k : (*kraje))
			jednotky->insertValid(k->getKey(), k->accessData());
	int fV;
	cout << "Filter nazov 1-> ano, 2-> nie: ";
	cin >> fV;
	if (fV == 1)
	{
		string volbaFilter1;
		FilterNazov<Area*> *filterN = new FilterNazov<Area*>;
		KriteriumNazov<Area*> *krN = new KriteriumNazov<Area*>;
		cout << "Zadajte nazov: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		getline(cin, volbaFilter1);
		filterN->setAlfa(volbaFilter1);
		for (auto k : (*jednotky))
			if (filterN->over(k->accessData(), *krN))
				jednotky2->insertValid(k->getKey(), k->accessData());
		delete jednotky;
		jednotky = new structures::SortedSequenceTable<string, Area*>();
		for (auto k : (*jednotky2))
			jednotky->insertValid(k->getKey(), k->accessData());
		delete jednotky2;
		jednotky2 = new structures::SortedSequenceTable<string, Area*>();
		delete krN;
		delete filterN;
	}
	cout << "Filter pocet volicov 1-> ano, 2-> nie: ";
	cin >> fV;
	if (fV == 1)
	{
		string volbaFilter1;
		string volbaFilter2;
		KriteriumVolici<Area*> *krV = new KriteriumVolici<Area*>;
		FilterVolici<Area*> *filterV = new FilterVolici<Area*>;
		cout << "Zadajte pocet volicov od: ";
		cin >> volbaFilter1;
		cout << "Zadajte pocet volicov do: ";
		cin >> volbaFilter2;
		filterV->setAlpha(atoi(volbaFilter1.c_str()));
		filterV->setBeta(atoi(volbaFilter2.c_str()));
		krV->set(kolo);
		for (auto k : (*jednotky))
			if (filterV->over(k->accessData(), *krV))
				jednotky2->insertValid(k->getKey(), k->accessData());
		delete jednotky;
		jednotky = new structures::SortedSequenceTable<string, Area*>();
		for (auto k : (*jednotky2))
			jednotky->insertValid(k->getKey(), k->accessData());
		delete jednotky2;
		jednotky2 = new structures::SortedSequenceTable<string, Area*>();
		delete krV;
		delete filterV;
	}
	cout << "Filter ucast volicov 1-> ano, 2-> nie: ";
	cin >> fV;
	if (fV == 1)
	{
		string volbaFilter1;
		string volbaFilter2;
		string volbaKrit1;
		KriteriumUcast<Area*> *krU = new KriteriumUcast<Area*>;
		FilterUcast<Area*> *filterU = new FilterUcast<Area*>;
		cout << "Zadajte ucast volicov v % od: ";
		cin >> volbaFilter1;
		cout << "Zadajte pocet volicov v % do: ";
		cin >> volbaFilter2;
		filterU->setAlpha(atoi(volbaFilter1.c_str()));
		filterU->setBeta(atoi(volbaFilter2.c_str()));
		krU->set(kolo);
		for (auto k : (*jednotky))
			if (filterU->over(k->accessData(), *krU))
				jednotky2->insertValid(k->getKey(), k->accessData());
		delete jednotky;
		jednotky = new structures::SortedSequenceTable<string, Area*>();
		for (auto k : (*jednotky2))
			jednotky->insertValid(k->getKey(), k->accessData());
		delete jednotky2;
		jednotky2 = new structures::SortedSequenceTable<string, Area*>();
		delete krU;
		delete filterU;
	}
	for (auto k : (*jednotky))
		vyfiltrovane->insertValid(k->getKey(), k->accessData());
	delete jednotky;
	delete jednotky2;
}

void Spravca::vypisanieVysledkovKandidata(bool sort)
{
	int kolo;
	cout << "Ktore kolo: " << endl << "\t1-> 1. kolo" << endl << "\t2-> 2. kolo" << endl << "\tVolba: ";
	cin >> kolo;
	vyfiltruj(kolo);
	string volbaFilter1;
	FilterMeno<Kandidat*> *filterM = new FilterMeno<Kandidat*>;
	KriteriumMeno<Kandidat*> *krM = new KriteriumMeno<Kandidat*>;
	KriteriumOdovzdaneHlasy<Area*> *krH = new KriteriumOdovzdaneHlasy<Area*>;
	krH->setKolo(kolo);
	cout << "\tMeno kandidata : ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, volbaFilter1);
	filterM->setAlfa(volbaFilter1);
	if (sort) {
		string zostVzost;
		int iVzZost;
		cout << "Zoradit: " << endl;
		cout << "\t1-> Zostupne" << endl;
		cout << "\t2-> Vzostupne" << endl;
		cout << "\tVolba: ";
		cin >> zostVzost;
		if (zostVzost == "1")
			iVzZost = -1;
		else
			iVzZost = 1;
		structures::UnsortedSequenceTable<int, Area*>* jednotky = new structures::UnsortedSequenceTable<int, Area*>();
		for (auto k : (*vyfiltrovane))
			for (auto j : k->accessData()->getKandidati(kolo))
			{
				if (filterM->over(j->accessData(), *krM))
				{
					krH->setKandidat(*j->accessData());
					jednotky->insertValid(krH->over(k->accessData()), k->accessData());
				}
			}
		structures::HeapSort<int, Area*, int> *sort = new structures::HeapSort<int, Area*, int>;
		sort->sortbetter(*jednotky, *krH, iVzZost);
		delete vyfiltrovane;
		vyfiltrovane = new structures::SortedSequenceTable<string, Area*>();
		for (auto k : (*jednotky))
			vyfiltrovane->insertValid(k->accessData()->getNazov(), k->accessData());
		delete jednotky;
		delete sort;
	}
	for (auto k : (*vyfiltrovane))
		for (auto j : k->accessData()->getKandidati(kolo))
		{
			if (filterM->over(j->accessData(), *krM))
			{
				krH->setKandidat(*j->accessData());
				cout << k->accessData()->getNazov() << ": " << "Poc. zap. volicov: " << k->accessData()->getPocZapVolicov(kolo)	<< ", poc. vyd. obalok: " <<
					k->accessData()->getPocVydObalok(kolo) << ", " << j->accessData()->getMenoAPriezvisko() << ": " << krH->over(k->accessData()) << endl;
			}
		}
	delete filterM;
	delete krM;
	delete krH;
}

void Spravca::vypisanieVyberovychKriterii()
{
	int kolo;
	cout << "Ktore kolo: " << endl << "\t1-> 1. kolo" << endl << "\t2-> 2. kolo" << endl << "\tVolba: ";
	cin >> kolo;
	vyfiltruj(kolo);
	KriteriumNajmenejHlasov<Area*> *krMH = new KriteriumNajmenejHlasov<Area*>;
	krMH->setKolo(kolo);
	KriteriumNajviacHlasov<Area*> *krNH = new KriteriumNajviacHlasov<Area*>;
	krNH->setKolo(kolo);
	KriteriumNajmensiRozdiel<Area*> *krNR = new KriteriumNajmensiRozdiel<Area*>;
	for (auto k : (*vyfiltrovane))
	{
		cout << k->accessData()->getNazov() << ": Najmenej hlasov: " << krMH->over(k->accessData()) << ":";
		cout << krMH->getHlasy() << ", najviac hlasov: " << krNH->over(k->accessData()) << ":";
		cout << krNH->getHlasy() << ", najmensi rozdiel: " << krNR->over(k->accessData()) << ":";
		cout << krNR->getRozdiel() << endl;
	}	
	delete krNH;
	delete krMH;
	delete krNR;
}

void Spravca::vytvorKoalicie()
{
	int kolo;
	cout << "Ktore kolo: " << endl << "\t1-> 1. kolo" << endl << "\t2-> 2. kolo" << endl << "\tVolba: ";
	cin >> kolo;
	vyfiltruj(kolo);
	bool pridavanieKoalicii = true;
	bool pridavanieKandidatov = true;
	string dalsi;
	string meno;
	structures::ArrayList<KriteriumHlasyKoalicie<Area*>*>*tabulkaKoalicii = new structures::ArrayList<KriteriumHlasyKoalicie<Area*>*>();
	while (pridavanieKoalicii)
	{
		pridavanieKandidatov = true;
		KriteriumHlasyKoalicie<Area*>* novaKoalicia = new KriteriumHlasyKoalicie<Area*>();
		while (pridavanieKandidatov) 
		{
			cout << "Meno a priezvisko kandidata: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			getline(cin, meno);
			novaKoalicia->pridaj(meno);

			cout << "Pridat dalsieho? 1->ano/ 0->nie: ";
			cin >> dalsi;
			if (dalsi == "0")
			{
				pridavanieKandidatov = false;
			}
		}
		tabulkaKoalicii->add(novaKoalicia);
		cout << "Pridat dalsiu koaliciu? 1->ano/ 0->nie: ";
		cin >> dalsi;
		if (dalsi == "0")
		{
			pridavanieKoalicii = false;
		}
	}
	string zostVzost;
	int iVzZost;
	cout << "Zoradit: " << endl;
	cout << "\t1-> Zostupne" << endl;
	cout << "\t2-> Vzostupne" << endl;
	cout << "\tVolba: ";
	cin >> zostVzost;
	if (zostVzost == "1")
		iVzZost = -1;
	else
		iVzZost = 1;
	structures::HeapSort<string, Area*, int> *sort = new structures::HeapSort<string, Area*, int>();
	structures::UnsortedSequenceTable<string, Area*>* jednotky = new structures::UnsortedSequenceTable<string, Area*>();
	for (auto k : (*vyfiltrovane))
		jednotky->insertValid(k->getKey(), k->accessData());
	for (auto k : (*tabulkaKoalicii))
	{
		sort->sortbetter(*jednotky, *k, iVzZost);
		cout << k->getKandidati() << endl;
		for (auto a : (*jednotky))
		{
			cout << a->accessData()->getNazov() << ": ";
			cout << k->over(a->accessData()) << endl;
		}
		cout << endl;
	}
	delete sort;
	delete jednotky;
	for (auto k : (*tabulkaKoalicii))
		delete k;
	delete tabulkaKoalicii;
}



Spravca::~Spravca()
{
	for (auto k : (*kraje))
	{
		delete k->accessData();
	}
	delete kraje;
	for (auto k : (*okresy))
	{
		delete k->accessData();
	}
	delete okresy;
	for (auto k : (*obce))
	{
		delete k->accessData();
	}
	delete obce;
	delete vyfiltrovane;
}
