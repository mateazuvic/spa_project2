#include <iostream>
#include "merge_sort.h"

using namespace std;

void merge_sort(vector<string>& bar) {

    int brojac = 0;

    if (bar.size() <= 1) return;

    int mid = bar.size() / 2;
    vector<string> left;
    vector<string> right;

    for (int j = 0; j < mid; j++)
        left.push_back(bar[j]);
    for (int j = 0; j < (bar.size()) - mid; j++)
        right.push_back(bar[mid + j]);
         brojac--;

    merge_sort(left);
    brojac++;
    merge_sort(right);
    brojac++;
    
    mergeS(left, right, bar);
}
void mergeS(vector<string>& left, vector<string>& right, vector<string>& bars)
{
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR)
    {
        if (left[j].size() < right[k].size()) {
            bars[i] = left[j];
            j++;
        }
        else {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL) {
        bars[i] = left[j];
        j++; i++;
    }
    while (k < nR) {
        bars[i] = right[k];
        k++; i++;
    }
}

