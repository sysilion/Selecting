/*
 * ith_best.c
 *
 *  Created on: 2015. 3. 30.
 *      Author: Administrator
 */


#include "selecting.h"

void ith_best() {
	extern int *input;
	int i, x, result;

	// input array size
	extern int data_size;

	// Time check variable
	double time;
	BOOL err;

	CHECK_TIME_START;
//	for (x = 0; x < LOOP_COUNT; x++) {
		result = Find_ith_Best(input, 0, data_size, 2);
//		if (x % (LOOP_COUNT / 10) == 0) printf("*");
//		printf("Selecting Result --> input[%d] : %d\n", result, input[result]);
//	}ad
	CHECK_TIME_END(time, err);

//	printf(" Calc Time = %.6fms\n", time/ LOOP_COUNT);
	printf("%.6f\n", time / LOOP_COUNT);
}

int Find_ith_Best(int array[], int start, int end, int i){
	int result;

//	result = Split(array, );

	return result;
}

int Split(int array[], int start, int end, int pivot_loc) {
	int mid = floor((start + end) / 2);
	int left = Find_Max(array, start, mid);
	int right = Find_Max(array, mid + 1, end);

	if (array[left] > array[right]) {
		array[left] = array[right];
		return Find_Max(array, start, mid);
	} else {
		array[right] = array[left];
		return Find_Max(array, mid + 1, end);
	}
}

