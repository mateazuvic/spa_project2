#include "selection_sort.h"
#include <iostream>



using namespace std;

vector<string> selection_sort(vector<string>& v1)
{
	for (int i = 0; i < v1.size() - 1; i++) {
		int min_index = i;
		string minValue = v1[i];
		for (int j = i + 1; j < v1.size(); j++) {
			if (v1[j].compare(v1[min_index]) < 0) {
				min_index = j;
			}
		}
		swap(v1[i], v1[min_index]);

	}
	return v1;
}
