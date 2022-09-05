#include "Movie.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>

Movie::Movie()
{
}

Movie::Movie(int rank, string naziv, string zanr, string opis, string direktor, string glumci, int godina_izdanja, int trajanje, double rejting, int glasovi, double zarada, int metascore)
{
	set_naziv(naziv);
	set_opis(opis);
	set_godina_izdanja(godina_izdanja);
	set_zarada(zarada);
	this->rank = rank;
	this->zanr = zanr;
	this->direktor = direktor;
	this->glumci = glumci;
	this->trajanje = trajanje;
	this->rejting = rejting;
	this->glasovi = glasovi;
	this->metascore = metascore;
}

Movie::Movie(string naziv, int godina_izdanja)
{
	set_godina_izdanja(godina_izdanja);
	set_naziv(naziv);
}


void Movie::set_naziv(string naziv)
{
	this->naziv = naziv;
}

void Movie::set_opis(string opis)
{
	this->opis = opis;
}

void Movie::set_godina_izdanja(int godina_izdanja) 
{
	this->godina_izdanja = godina_izdanja;
}

void Movie::set_zarada(double zarada)
{
	this->zarada = zarada;
}

string Movie::get_naziv() const
{
	return naziv;
}

string Movie::get_opis()
{
	return opis;
}

string Movie::get_zanr()
{
	return zanr;
}

int Movie::get_godina_izdanja() const
{
	return godina_izdanja;
}

double Movie::get_zarada()
{
	return zarada;
}

int Movie::get_metascore()
{
	return metascore;
}

string Movie::to_string() const
{
	stringstream ss;
	ss << "Naziv: " << naziv << endl
		<< "Opis: " << opis << endl
		<< "Godina izdanja: " << godina_izdanja << endl
		<< "Zarada: " << zarada  << setprecision(2) << endl;
	return ss.str();
}


