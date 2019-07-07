#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures {
	/// <summary> Triedenie Heap sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T, typename O>
	class HeapSort : public Sort<K, T, O> {
	public:
		HeapSort();
		HeapSort(int(*cmp_)(O item1, O item2, int smer));
		/// <summary> Utriedi tabulku triedenim Heap sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override {};
		void sortbetter(UnsortedSequenceTable<K, T>& table, Kriterium<O, T>& kr, int smer) override;
		int(*cmp_)(O item1, O item2, int smer);
	};

	template<typename K, typename T, typename O>
	inline HeapSort<K, T, O>::HeapSort() :cmp_(compareData) {
	}

	template<typename K, typename T, typename O>
	inline HeapSort<K, T, O>::HeapSort(int(*cmp_)(O item1, O item2, int smer)) :
		cmp_(cmp_) {
	}

	template<typename O>
	inline int compareData(O item1, O item2, int smer) {
		if (item1 < item2)
			return -1*smer;
		else if (item1 > item2)
			return 1*smer;
		else
			return 0;
	}

	template<typename K, typename T, typename O>
	inline void HeapSort<K, T, O>::sortbetter(UnsortedSequenceTable<K, T>& table, Kriterium <O, T>& kr, int smer) {
		bool zmena = false;
		int aktualny;
		int otec;
		int lavy;
		int pravy;
		int max;
		for (int i = 1; i < table.size(); i++) {
			aktualny = i;
			do 
			{
				zmena = false;
				otec = (aktualny - 1) / 2;
				if (aktualny > 0 && cmp_(kr.over(table.getItemAtIndex(aktualny).accessData()), kr.over(table.getItemAtIndex(otec).accessData()), smer) > 0) {
					table.swap(aktualny, otec);
					aktualny = otec;
					zmena = true;
				}
			} while (zmena);
		}
		
		for (int i = table.size() - 1; i >= 1; i--) {
			table.swap(0, i);
			aktualny = 0;
			do 
			{
				zmena = false;
				lavy = (aktualny * 2) + 1;
				pravy = (aktualny * 2) + 2;
				if (lavy < i && pravy < i)
					max = cmp_(kr.over(table.getItemAtIndex(lavy).accessData()), kr.over(table.getItemAtIndex(pravy).accessData()), smer) > 0 ? lavy : pravy;
				else
					max = lavy < i ? lavy : pravy;
				if (max < i && cmp_(kr.over(table.getItemAtIndex(max).accessData()), kr.over(table.getItemAtIndex(aktualny).accessData()), smer) >0) 
				{
					table.swap(max, aktualny);
					aktualny = max;
					zmena = true;
				}
			} while (zmena);
		}
	}

}