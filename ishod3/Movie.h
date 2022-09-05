#pragma once
#include <string>


using namespace std;

class Movie
{
public:
	Movie();
	Movie(int rank, string naziv, string zanr, string opis, string direktor,
		string glumci, int godina_izdanja, int trajanje, double rejting, int glasovi,
		double zarada, int metascore);
	Movie(string naziv, int godina_izdanja);
	Movie(string naziv);
	void set_naziv(string naziv);
	void set_opis(string opis);
	void set_godina_izdanja(int godina_izdanja);
	void set_zarada(double zarada);
	string get_naziv() const;
	string get_opis();
	string get_zanr();
	int get_godina_izdanja() const;
	double get_zarada();
	int get_metascore();
	string to_string() const;
	
	

private:
	int rank;
	string naziv;
	string zanr;
	string opis;
	string direktor;
	string glumci;
	int godina_izdanja;
	int trajanje;
	double rejting;
	int glasovi;
	double zarada;
	int metascore;
	
	
};

//zadatak 5 (i3)
struct komparator
{
	bool operator() (const Movie& m1, const Movie& m2) const
	{
		return m1.get_godina_izdanja() < m2.get_godina_izdanja();
	}
};

