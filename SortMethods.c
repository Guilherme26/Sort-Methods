#include "SortMethods.h"

void resetHeap(int *vector, int cur_index, int vec_size, int (*compare)(int, int)){
	int aux = 0, left_son = 0, right_son = 0, father_index = 0;

	while( 1 ){
		left_son = 2 * cur_index;
		right_son = (2 * cur_index) + 1;
		
		if(left_son <= vec_size && (*compare)(vector[left_son], vector[cur_index]))
			father_index = left_son;
		else
			father_index = cur_index;
		if(right_son <= vec_size && (*compare)(vector[right_son], vector[father_index]))
			father_index = right_son;
		if(father_index != cur_index){
			aux = vector[cur_index];
			vector[cur_index] = vector[father_index];
			vector[father_index] = aux;
			cur_index = father_index;
		}
		else
			return;
	}
}

void buildHeap(int *vector, int vec_size, int (*compare)(int, int)){
	int i = 0;

	for(i = (vec_size/2); i > 0; i--){
		resetHeap(vector, i, vec_size, compare);
	}
}

void heapsort(int *vector, int vec_size, int (*compare)(int, int)){
	int i = 0, aux = 0;

	buildHeap(vector, vec_size, compare);
	for(i = vec_size; i > 1; i--){
		aux = vector[1];
		vector[1] = vector[i];
		vector[i] = aux;
		resetHeap(vector, 1, i-1, compare);
	}
}