/* 
Jessica Fang, Justin Gonzalez, Juan Pablo Zambrano
CSCE 221-512
Bubble Sort
*/

#include "sort.h"

void BubbleSort::sort(int A[], int size)			
{
	for(int k = 1; k < size; ++k) {
		bool cont = false;
		for(int j = 0; j < size - k; ++j) {
			++num_cmps;
			if(A[j+1] < A[j]) {
				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				cont = true;
			}
		}
		if(!cont) break;
	}
}
