/* 
Jessica Fang, Justin Gonzalez, Juan Pablo Zambrano
CSCE 221-512
Insertion Sort
*/

#include "sort.h"

void InsertionSort::sort(int A[], int size){
	for (int k = 1; k < size; k++ ){
		int tmp = A[k], j = k;
		if(tmp >= A[j-1])
			++num_cmps;
		for( ; j > 0 && tmp < A[j-1]; j--)
		{
			++num_cmps;
			A[j] = A[j-1];	
		}
		A[j] = tmp;
	}
}


