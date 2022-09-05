#include "insertion_sort_swap.h"
#include <iostream>

using namespace std;

unsigned int insertion_sort_swap(vector<string>& v2) {
	unsigned int brojac= 0;

	for (int i = 1; i < v2.size(); i++) { 
		for (int j = i; j > 0 && v2[j - 1] > v2[j]; j--) {
			
				swap(v2[j], v2[j - 1]);
				brojac++;
				
			
			
		}
	}
	return brojac;
}