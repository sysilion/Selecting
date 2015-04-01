/*
 * ith_best.c
 *
 *  Created on: 2015. 3. 30.
 *      Author: Administrator
 */


#include "selecting.h"

int pivot_loc;

void ith_best() {
	extern int *input;
	int i, x, result;

	// input array size
	extern int data_size;

	// Time check variable
	double time;
	BOOL err;

	int search_nth = 2;

	CHECK_TIME_START;
	for (x = 0; x < LOOP_COUNT; x++) {
		result = Find_ith_Best(input, 0, data_size-1, search_nth);
//		if (x % (LOOP_COUNT / 10) == 0) printf("*");
//		printf("Selecting Result %dth --> input[%d] : %d\n", search_nth, result, input[result]);
	}
	CHECK_TIME_END(time, err);

//	printf(" Calc Time = %.6fms\n", time/ LOOP_COUNT);
	printf("%.6f\n", time / LOOP_COUNT);
}

int Find_ith_Best(int array[], int start, int end, int i){
	extern double factor;
	int index = (int)(rand()*factor)%end + 1;
	pivot_loc = Split(array, start, end, index);

	if (end - pivot_loc < i-1){
		pivot_loc = Find_ith_Best(array, start, pivot_loc-1, i-(end-pivot_loc+1));
	} else if (end - pivot_loc > i-1) {
		pivot_loc = Find_ith_Best(array, pivot_loc + 1, end, i);
	} else {
		return pivot_loc;
	}
}

int Split(int array[], int start, int end, int pivot_loc) {
	int i;
	int pivot = array[pivot_loc];
	int temp = array[start];
	array[start] = array[pivot_loc];
	array[pivot_loc] = temp;
	pivot_loc = start;

	for (i = start+1; i < end; i++){
		if (pivot > array[i]){
			pivot_loc++;
			temp = array[i];
			array[i] = array[pivot_loc];
			array[pivot_loc] = temp;
		}
	}
	temp = array[start];
	array[start] = array[pivot_loc];
	array[pivot_loc] = temp;

	return pivot_loc;
}

