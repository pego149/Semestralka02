#pragma once
#pragma once
#include <iostream>
#include "Kriterium.h"
#include "Area.h"

using namespace std;
template<typename T, typename O>
class Filter
{
public: virtual bool over(O& o, Kriterium<T, O>& c) = 0;
};

template<typename T, typename O>
class Filter_fi : public Filter<T, O>
{
	private: T alpha;
	public: bool over(O& o, Kriterium<T, O>& c) override { return c.over(o) == alpha; }
			void setAlfa(const T& in) { alpha = *&in; };
};

template <typename T, typename O>
class Filter_FI : public Filter<T, O>
{
	private: T alpha;
			 T beta;
	public: bool over(O& o, Kriterium<T, O>& c) override { T result = c.over(o); return result >= alpha && result <= beta; }
			void setAlpha(const T& in) { alpha = *&in; };
			void setBeta(const T& in) { beta = *&in; };
};

template <typename O>
class FilterNazov : public Filter_fi<string, O>
{
	private: string alpha;
	public: bool over(O& o, Kriterium<string ,O>& c) override { return c.over(o) == alpha; }
			void setAlfa(const string in) { alpha = in; };
};

template <typename O>
class FilterVolici : public Filter_FI<int, O>
{
private: int alpha;
		 int beta;
public: bool over(O& o, Kriterium<int, O>& c) override { int result = c.over(o); return result >= alpha && result <= beta; }
		void setAlpha(int in) { alpha = in; };
		void setBeta(int in) { beta = in; };
};

template <typename O>
class FilterUcast : public Filter_FI<double, O>
{
private: double alpha;
		 double beta;
public: bool over(O& o, Kriterium<double, O>& c) override { double result = c.over(o); return result >= alpha && result <= beta; }
		void setAlpha(const double in) { alpha = in; };
		void setBeta(const double in) { beta = in; };
};

template <typename O>
class FilterPrislusnostObce : public Filter_fi<bool, O>
{
private: bool alpha = true;
public: bool over(O& o, Kriterium<bool, O>& c) override { return c.over(o) == alpha; }
		void setAlfa(const bool in) { alpha = in; };
};

template <typename O>
class FilterMeno : public Filter_fi<string, O>
{
private: string alpha;
public: bool over(O& o, Kriterium<string, O>& c) override { return c.over(o) == alpha; }
		void setAlfa(const string in) { alpha = in; };
};