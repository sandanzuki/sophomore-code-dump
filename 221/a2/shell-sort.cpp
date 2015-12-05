/*
Jessica Fang, Justin Gonzalez, Juan Pablo Zambrano
CSCE 221-512
Shell Sort
*/

#include "sort.h"
#include <iostream>

int next_gap(int gap){ 
    if (gap == 2) return 1; 
    else return (int) (gap/2.2); 
}

void ShellSort::sort(int A[], int size){
	int gap = size/2;
    for(; gap > 0; gap = next_gap(gap)){
		for(int i = gap; i < size; ++i){
			int temp = A[i];
			int j = i;
            if(temp >= A[j-gap]){
                ++num_cmps;
            }                
            while(j >= gap && temp < A[j-gap]){
                ++num_cmps;
                A[j] = A[j-gap];
                j-= gap;
            }
            A[j] = temp;
            
		}
	}
}
