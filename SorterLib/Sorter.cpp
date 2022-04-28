#include "Sorter.h"


void Sorter::swap(Comparable** pItems, int i, int j)
{
		Comparable* tmp = pItems[j];
		pItems[i] = pItems[j];
		pItems[j] = tmp;
}

void Sorter::bubbleSort(Comparable** pItems, unsigned itemCount) {
	for (int i = 0; i < itemCount-1; ++i) {
		for (int j = 1; i < itemCount; ++i) {
			if (pItems[i] > pItems[j]) {
				swap(pItems, i, j);
			}
		}
	}
}
