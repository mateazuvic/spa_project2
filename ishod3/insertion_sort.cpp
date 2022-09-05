#include <iostream>
#include "insertion_sort.h"
using namespace std;

vector<string> insertion_sort(vector<string>& v2) {
	for (int i = 1; i < v2.size(); i++) {
		for (int j = i; j > 0 && v2[j - 1] > v2[j]; j--) {

			swap(v2[j], v2[j - 1]);
			



		}
	}
	return v2;
}


