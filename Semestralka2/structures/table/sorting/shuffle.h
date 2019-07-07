#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"
#include <random>
#include <chrono>

namespace structures
{

	/// <summary> Pomiesa prvky v tabulke. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T, typename O>
	class Shuffle : public Sort<K, T, O>
	{
	public:
		/// <summary> Pomiesa prvky v tabulke. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
		void sortbetter(UnsortedSequenceTable<K, T>& table, Kriterium<O, T>& kr, int smer) override {};
	};

	template<typename K, typename T, typename O>
	inline void Shuffle<K, T, O>::sort(UnsortedSequenceTable<K, T>& table)
	{
		int size = static_cast<int>(table.size());
		unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
		std::default_random_engine generator(seed);
		std::uniform_int_distribution<int> uniform(0, size - 1);

		for (int i = 0; i < size * 2; i++)
		{
			table.swap(uniform(generator), uniform(generator));
			notify();
		}
	}

}