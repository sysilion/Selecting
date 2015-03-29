/*
 * dc_second.c
 *
 *  Created on: 2015. 3. 26.
 *      Author: Administrator
 */

#include "selecting.h"

void dc_second() {
	extern int *input;
	int i, x, result;

	// input array size
	extern int data_size;

	// Time check variable
	double time;
	BOOL err;

	CHECK_TIME_START;
//	for (x = 0; x < LOOP_COUNT; x++) {

		result = Find_Second_Max_DC(input, 0, data_size);
//		if (x % (LOOP_COUNT / 10) == 0) printf("*");
//		printf("Selecting Result --> input[%d] : %d\n", result, input[result]);
//	}
	CHECK_TIME_END(time, err);

//	printf(" Calc Time = %.6fms\n", time/ LOOP_COUNT);
	printf("%.6f\n", time / LOOP_COUNT);
}

int Find_Second_Max_DC(int array[], int start, int end) {
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
