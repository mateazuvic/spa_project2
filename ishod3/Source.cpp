#include <iostream>	
#include "Movie.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <map>
#include <queue>
#include <chrono>
#include <ctime>
#include <unordered_map>
#include <list>
#include "selection_sort.h"
#include "selection_sort_swap.h"
#include "insertion_sort.h"
#include "insertion_sort_swap.h"
#include "merge_sort.h"



using namespace std;
using namespace std::chrono;

// zadatak 2 (i3)
template<typename T>
 T convert(string& s)
{
	stringstream c(s);
	T t;
	c >> t;
	return t;
}

 // zadatak 2 (i3)
void ucitaj(ifstream& in, vector<Movie>& v)
{
	
	string line;
	getline(in, line);
	while (getline(in, line))
	{
		
		stringstream ss(line);
		string temp;

		
		getline(ss, temp, ',');
		int rank = convert<int>(temp);
		getline(ss, temp, ',');
		string naziv = temp;
		if (ss.peek() == '"')
		{
			getline(ss, temp, '"');
			getline(ss, temp, '"');
		}
		else
		{
			getline(ss, temp, ',');
		}
		string zanr = temp;

		if (ss.peek()== '"')
		{
			getline(ss, temp, '"');
			getline(ss, temp, '"');
			
			
		}
		else
		{
			
			getline(ss, temp, ',');
			getline(ss, temp, '.');
		}
		string opis = temp;

		if (ss.peek()=='"')
		{
			getline(ss, temp, '"');
			getline(ss, temp, '"');
		}
		else
		{
			getline(ss, temp, ',');
			getline(ss, temp, ',');

		}
		string direktor = temp;

		if (ss.peek() == '"')
		{
			getline(ss, temp, '"');
			getline(ss, temp, '"');
			
		}
		else
		{
			getline(ss, temp, ',');
			getline(ss, temp, '"');
		}
		string glumci = temp;

		if (ss.peek() == '"')
		{
			getline(ss, temp, '"');
			getline(ss, temp, '"');
		}
		else 
		{
			getline(ss, temp, ',');
			getline(ss, temp, ',');
		}
		int godina_izdanja = convert<int>(temp);

		getline(ss, temp, ',');
		int trajanje = convert<int>(temp);

		getline(ss, temp, ',');
		double rejting = convert<double>(temp);

		getline(ss, temp, ',');
		int glasovi = convert<int>(temp);

		getline(ss, temp, ',');
		double zarada = convert<double>(temp);

		getline(ss, temp, ',');
		int metascore = convert<int>(temp);
		
		v.emplace_back(rank, naziv, zanr, opis, direktor, glumci, godina_izdanja, trajanje, rejting, glasovi, zarada, metascore);

	}
}

// zadatak 2 (i3) -- provjera nakon parsiranja
void print(Movie& film)
{
	cout << film.to_string() << endl;
}


//zadatak 6 (i3)
void search(multimap<char, string>& m, vector<string> vec)
{
	bool dalje;
	
	do
	{
		char slovo;
		cout << "Unesite (veliko tiskano) slovo : ";
		cin >> slovo;

		auto found = m.equal_range(slovo);


		if (found.first != found.second)
		{
			cout << "Pronadjeni filmovi:" << endl;
			for (auto it = found.first; it != found.second; ++it)
			{
				//cout << it->second << "    ";
				vec.push_back(it->second);
			}
			cout << endl;
			
		}
		else
		{
			cout << "Nema filmova koji pocinju tim slovom" << endl;
		}

		for (auto& n : vec)
		{
			cout << n << endl;
		}
		

		cout << "Dalje (1=da, 0=ne)? ";
		cin >> dalje;
	} while (dalje);
}


// zadatak 3 i 4 (i3)
void search2(multimap<int, string> m2, vector<pair<int, string>> vector, list<pair<int, string>> list) {

	int min;
	cout << "Unesite min metascore: ";
	cin >> min;
	int max;
	cout << "Unesite max metascore: ";
	cin >> max;

	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> found;
	
	for (int i = min; i <= max; i++)
	{
		 auto begin1 = high_resolution_clock::now();
	     found = m2.equal_range(i);
		 auto end1 = high_resolution_clock::now();
		 if (found.first != found.second)
		 {
			 cout << "Pronadjeni filmovi metascore-a " << i << endl;
			 for (auto it = found.first; it != found.second; ++it)
			 {
				 cout << it->first << " ---  " << it->second << "    ";

			 }
			 cout << endl;

		 }
		 auto begin2 = high_resolution_clock::now();
		 for (int i = 0; i < vector.size(); i++)
		 {
			 if (vector[i].first == i)
			 {

				 //cout << vector[i].second << endl;
			 }
		 }
		 auto end2 = high_resolution_clock::now();


		 auto begin3 = high_resolution_clock::now();
		 for (auto it = list.begin(); it != list.end(); ++it)
		 {
			 if ((*it).first == i)
			 {

				 //cout << (*it).second << endl;
			 }
		 }
		 auto end3 = high_resolution_clock::now();

		 int trajanje_mm = duration_cast<nanoseconds>(end1 - begin1).count();
		 int trajanje_vec = duration_cast<nanoseconds>(end2 - begin2).count();
		 int trajanje_lis = duration_cast<nanoseconds>(end3 - begin3).count();



		 if (trajanje_mm < trajanje_vec && trajanje_mm < trajanje_lis)
		 {
			 cout << "Najbrzi: unordered_multimap - " << trajanje_mm << endl;
			 if (trajanje_vec < trajanje_lis)
			 {
				 cout << "Srednji: vector - " << trajanje_vec << endl;
				 cout << "Najsporiji: list - " << trajanje_lis << endl;
			 }
			 else
			 {
				 cout << "Srednji: list - " << trajanje_lis << endl;
				 cout << "Najsporiji: vector - " << trajanje_vec << endl;
			 }
		 }

		 if (trajanje_vec < trajanje_mm && trajanje_vec < trajanje_lis)
		 {
			 cout << "Najbrzi: vector - " << trajanje_vec << endl;
			 if (trajanje_mm < trajanje_lis)
			 {
				 cout << "Srednji: unordered_multimap - " << trajanje_mm << endl;
				 cout << "Najsporiji: list - " << trajanje_lis << endl;
			 }
			 else
			 {
				 cout << "Srednji: list - " << trajanje_lis << endl;
				 cout << "Najsporiji: unordered_multimap - " << trajanje_mm << endl;
			 }
		 }

		 if (trajanje_lis < trajanje_mm && trajanje_lis < trajanje_vec)
		 {
			 cout << "Najbrzi: list - " << trajanje_lis << endl;
			 if (trajanje_vec < trajanje_mm)
			 {
				 cout << "Srednji: vector - " << trajanje_vec << endl;
				 cout << "Najsporiji: unordered_multimap - " << trajanje_mm << endl;
			 }
			 else
			 {
				 cout << "Srednji: unordered_multimap - " << trajanje_mm << endl;
				 cout << "Najsporiji: vector - " << trajanje_vec << endl;
			 }
		 }
	}
	
}


//zadatak 5 (i4)
bool issorted(vector<string>& v)
{
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] < v[i - 1])
		{
			return false;
		}
	}
	return true;
}
void bogosort(vector<string>& v)
{
	while (!issorted(v))
	{
		 next_permutation(v.begin(), v.end());
		 for (int i = 0; i < v.size(); i++)
		 {
			 cout << v[i] << endl;
		 }
		 cout << endl;
	}
}

// zadatak 4 (i4)
int gen_rnd(int min, int max) {

	return rand() % (max - min + 1) + min;

}

//zadatak 2 i 3 (i5)
void search_un_mm(unordered_multimap<string, string>& un_mm, vector<pair<string, string>> v5, list<pair<string, string>> l) {

	cout << "Izaberite zanr filma: ";
	string zanr;
	cin >> zanr;

	auto begin1 = high_resolution_clock::now();
	auto found = un_mm.equal_range(zanr);
	auto end1 = high_resolution_clock::now();

	if (found.first != found.second)
	{
		//cout << "Pronadeni filmovi zanra " << zanr << ":" << endl;
		for (auto it = found.first; it != found.second; ++it)
		{
			cout << it->second << endl;
		}
	}
	else
	{
		cout << "Pokusajte ponovno upisati skupinu zanrova! U protivnom ne postoji film tog zanra." << endl;
	}

	auto begin2 = high_resolution_clock::now();
	for (int i = 0; i < v5.size(); i++)
	{
		if (v5[i].first == zanr)
		{
			
			//cout << v5[i].second << endl;
		}
		
	}
	auto end2 = high_resolution_clock::now();

	auto begin3 = high_resolution_clock::now();
	for (auto it  = l.begin(); it != l.end(); ++it)
	{
		if ((*it).first == zanr)
		{
			
			//cout << (*it).second << endl;
		}
	}
	auto end3 = high_resolution_clock::now();

	int trajanje_mm = duration_cast<nanoseconds>(end1 - begin1).count();
	int trajanje_vec = duration_cast<nanoseconds>(end2 - begin2).count();
	int trajanje_lis = duration_cast<nanoseconds>(end3 - begin3).count();

	

	if (trajanje_mm < trajanje_vec && trajanje_mm < trajanje_lis)
	{
		cout << "Najbrzi: unordered_multimap - " << trajanje_mm << endl;
		if (trajanje_vec < trajanje_lis)
		{
			cout << "Srednji: vector - " << trajanje_vec << endl;
			cout << "Najsporiji: list - " << trajanje_lis << endl;
		}
		else
		{
			cout << "Srednji: list - " << trajanje_lis << endl;
			cout << "Najsporiji: vector - " << trajanje_vec << endl;
		}
	}

	if (trajanje_vec < trajanje_mm && trajanje_vec < trajanje_lis)
	{
		cout << "Najbrzi: vector - " << trajanje_vec << endl;
		if (trajanje_mm < trajanje_lis)
		{
			cout << "Srednji: unordered_multimap - " << trajanje_mm << endl;
			cout << "Najsporiji: list - " << trajanje_lis << endl;
		}
		else
		{
			cout << "Srednji: list - " << trajanje_lis << endl;
			cout << "Najsporiji: unordered_multimap - " << trajanje_mm << endl;
		}
	}

	if (trajanje_lis < trajanje_mm && trajanje_lis < trajanje_vec)
	{
		cout << "Najbrzi: list - " << trajanje_lis << endl;
		if (trajanje_vec < trajanje_mm)
		{
			cout << "Srednji: vector - " << trajanje_vec << endl;
			cout << "Najsporiji: unordered_multimap - " << trajanje_mm << endl;
		}
		else
		{
			cout << "Srednji: unordered_multimap - " << trajanje_mm << endl;
			cout << "Najsporiji: vector - " << trajanje_vec << endl;
		}
	}
	

}

//zadatak 5 (i5)
void trazi_film(unordered_map<string, string> m) {

	cin.ignore();
	string name;
	cout << "Unesite naziv filma: ";
	getline(cin, name);

	string s;
	cout << "Unesite string: ";
	getline(cin, s);

	

	auto found = m.find(name);
	if (found != m.end()) {

		cout << found->second << endl;
		for (int i = 0; i < s.length(); i++)
		{
			for (auto it = found->second.begin(); it != found->second.end(); ++it)
			{
				if (s[i] == *it)
				{
					cout << "Moze - " << *it << endl;
					break;
					
				}
				

			}
		}
	}
	else
	{
		cout << "Nema filma tog naziva!" << endl;
	}

}


int main()
{

	//1. zadatak (i3, i4, i5)

	int odabir;

	do
	{
		cout << "--------IZBORNIK--------" << endl << endl;
		cout << "Pretraga po Metascoreu(1)" << endl;
		cout << "Prikaz po godini(2)" << endl;
		cout << "Kopiranje u novi vektor(3)" << endl;
		cout << "Prikaz po generacijama(4)" << endl;
		cout << "Selection vs Insertion(5)" << endl
			<< "Pogodi trajanje(6)" << endl
			<< "Lets Bogo!(7)" << endl
			<< "The Merge Dance(8)" << endl
			<< "Pretraga po zanru(9)" << endl
			<< "Vizualiziraj(10)" << endl
			<< "Izrada stringa iz stringa(11)" << endl;


		cout << endl << "Odaberite (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11): ";
		cin >> odabir;

	} while (odabir != 1 && odabir != 2 && odabir != 3 && odabir != 4 && odabir != 5 && odabir != 6 && odabir != 7 && odabir != 8
		 && odabir != 9 && odabir != 10 && odabir != 11);

	Movie film;
	vector<Movie> v;

	ifstream in("SPA_PROJ_011_IMDB_data.csv");
	if (!in)
	{
		cout << "Nije moguce pristupiti datoteci" << endl;
		return 1;
	}

	ucitaj(in, v);
	in.close();

	//for_each(v.begin(), v.end(), print);  // provjera nakon parsiranja

	//zadatak 6 (i3)
	if (odabir == 3)
	{
		vector<string> vec;
		multimap<char, string> m;


		char slovo;
		for (int i = 0; i < v.size(); i++)
		{

			m.insert(pair<char, string>(v[i].get_naziv().c_str()[0], v[i].get_naziv()));
		}

		search(m, vec);

}

	//zadatak 5 (i3)
	if (odabir == 2)
	{
		priority_queue<Movie, vector<Movie>, komparator> pq;
		for (int i = 0; i < v.size(); i++)
		{
			pq.emplace(v[i].get_naziv(), v[i].get_godina_izdanja());
		}
		while (!pq.empty())
		{
			cout << pq.top().get_naziv() << " " << pq.top().get_godina_izdanja() << endl;
			pq.pop();
		}

	}

	//zadatak 3 i 4 (i3)
	if (odabir == 1)
	{
		multimap<int, string> m2;
		vector<pair<int, string>> vector;
		list<pair<int, string>> list;
		for (int i = 0; i < v.size(); i++)
		{
			m2.insert(pair<int, string>(v[i].get_metascore(), v[i].to_string()));
			vector.push_back(make_pair(v[i].get_metascore(), v[i].to_string()));
			list.push_back(make_pair(v[i].get_metascore(), v[i].to_string()));
		}
		search2(m2, vector, list);

	}

	
	//zadatak 2 i 3 (i4)
	if (odabir == 5)
	{
		vector<string> v1;
		vector<string> v2;

		for (int i = 0; i < v.size(); i++)
		{
			v1.push_back(v[i].get_naziv());
			v2.push_back(v[i].get_naziv());


		}
		auto begin1 = high_resolution_clock::now();
		selection_sort(v1);
		auto end1 = high_resolution_clock::now();
		cout << "Selection: " << duration_cast<milliseconds>(end1 - begin1).count() << " ms" << endl;

		auto begin2 = high_resolution_clock::now();
		insertion_sort(v2);
		auto end2 = high_resolution_clock::now();
		cout << "Insertion: " << duration_cast<milliseconds>(end2 - begin2).count() << " ms" << endl;

		/*for (auto& i : v1)
		{
			cout << i << endl;
		}
		for (auto& i : v2)
		{
			cout << i << endl;
		}*/

		v1.clear();
		v2.clear();

		for (int i = 0; i < v.size(); i++)
		{
			v1.push_back(v[i].get_naziv());
			v2.push_back(v[i].get_naziv());
		}


		cout << "Broj zamjena mjesta (Selection): " << selection_sort_swap(v1) << endl;
		cout << "Broj zamjena mjesta (Insertion): " << insertion_sort_swap(v2) << endl;

	}


	// zadatak 6 (i4)
	if (odabir == 8)
	{
		srand(time(nullptr));

		int n;
		cout << "Unesite n: ";
		cin >> n;

		vector<string> v3;

		random_shuffle(v.begin(), v.end());

		for (int i = 0; i < n; i++)
		{
			v3.push_back(v[i].get_naziv());

		}

		
			merge_sort(v3);
		

		for (auto& i : v3)
		{
			cout << i << endl;
		}
	}

	// zadatk 5 (i4)
	if (odabir == 7)
	{
		srand(time(nullptr));

		int nbr = 5;

		vector<string> v4;

		random_shuffle(v.begin(), v.end());

		for (int i = 0; i < nbr; i++)
		{
			v4.push_back(v[i].get_naziv());

		}

		bogosort(v4);

}

	//zadatak 4 (i4)
	if (odabir == 6)
	{
		srand(time(nullptr));

		int n = gen_rnd(1, 100000000);
		cout << n << endl;
		int misljenje;
		cout << "Vase misljenje o trajanju: ";
		cin >> misljenje;

		vector<int> polje;

		for (int i = 1; i <= n; i++)
		{
			polje.push_back(i);
		}
		

		auto begin = high_resolution_clock::now();
		random_shuffle(polje.begin(), polje.end());

		sort(polje.begin(), polje.end());

		binary_search(polje.begin(), polje.end(), 7);
		auto end = high_resolution_clock::now();
		cout << "Trajanje: " << duration_cast<milliseconds>(end - begin).count() << " ms" << endl;
		cout << "Razlika: " << (duration_cast<milliseconds>(end - begin).count()) - misljenje << " ms" << endl;
			
	}


	//zadatak 2 i 3 (i5)
	if (odabir == 9)
	{
		unordered_multimap <string, string> un_mm;
		vector<pair<string, string>> v5;
		list<pair<string, string>> l;

		for (int i = 0; i < v.size(); i++)
		{
			un_mm.insert(pair<string, string>(v[i].get_zanr(), v[i].to_string()));
			v5.push_back(make_pair(v[i].get_zanr(), v[i].to_string()));
			l.push_back(make_pair(v[i].get_zanr(), v[i].to_string()));
		}

		search_un_mm(un_mm, v5, l);

	}

	//zadatak 4 (i5)
	if (odabir == 10)
	{
		unordered_multimap<int, string> un_multi;
		for (int i = 0; i < v.size(); i++)
		{
			un_multi.insert(pair<int, string>(v[i].get_godina_izdanja(), v[i].get_naziv()));

		}

		for (unsigned i = 0; i < un_multi.bucket_count(); i++) {
			cout << "Bucket " << i << ":" << endl;
			for (auto it = un_multi.begin(i); it != un_multi.end(i); ++it) {

				cout << it->second << "  ---  ";
				
			}
			
			if (un_multi.bucket_size(i) == 0)
			{
				cout << " [EMPTY] " << endl;;
			}
			cout << endl;
		}
		
	}

		
	//zadatak 5 (i5)
	if (odabir == 11)
	{
		
		unordered_map<string, string> m;
		
		for (int i = 0; i < v.size(); i++)
		{
			m.insert(pair<string, string>(v[i].get_naziv(), v[i].get_opis()));
		}

		trazi_film(m);
	}


 return 0;
}