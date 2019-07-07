#include "structures/heap_monitor.h"
#include "Spravca.h"

Spravca spravca = Spravca();

int main() {
	initHeapMonitor();

	string in = "";
	while (spravca.getAktivne())
	{
		cout << "e-> Koniec" << endl << "1-> Vypisat info o jednotkach" << endl 
			<< "2-> Zoradit obce podla kriteria" << endl 
			<< "4-> Vyfiltrovat a zoradit obce podla kriteria" << endl 
			<< "5-> Vypisanie vysledkov kandidata v uzemnej jednotke"<< endl
			<< "6-> Zoradenie a vypisanie vysledkov kandidata v uzemnej jednotke" << endl 
			<< "7-> Vypisanie vyberovych kriterii" << endl
			<< "8-> vytvorenie koalicii" << endl << "Vyberte moznost: ";
		
		cin >> in;
		if (in == "e")
		{
			system("CLS");
			spravca.koniec();
		}
		else if (in == "1")
		{
			system("CLS");
			spravca.vypisInfoOJednotke();
		}
		else if (in == "2")
		{
			system("CLS");
			spravca.zoradObce();
		}
		else if (in == "4")
		{
			system("CLS");
			spravca.zoradObcePodlaFiltra();
		}
		else if (in == "5")
		{
			system("CLS");
			spravca.vypisanieVysledkovKandidata(false);
		}
		else if (in == "6")
		{
			system("CLS");
			spravca.vypisanieVysledkovKandidata(true);
		}
		else if (in == "7")
		{
			system("CLS");
			spravca.vypisanieVyberovychKriterii();
		}
		else if (in == "8")
		{
			system("CLS");
			spravca.vytvorKoalicie();
		}
	}
	return 0;
}