/*
 * dc_best_worst.c
 *
 *  Created on: 2015. 4. 1.
 *      Author: Administrator
 */

#include "selecting.h"

void dc_best_worst(){
	extern int *input;
	int i, x;

	BW result;

	// input array size
	extern int data_size;

	// Time check variable
	double time;
	BOOL err;

	CHECK_TIME_START;
	for (x = 0; x < LOOP_COUNT; x++) {
		result = Find_Best_Worst_DC(input, 0, data_size);
//		if (x % (LOOP_COUNT / 10) == 0) printf("*");
//		printf("Selecting Result --> input[%d] : %d, input[%d] : %d\n", result.worst, input[result.worst], result.best, input[result.best]);
	}
	CHECK_TIME_END(time, err);

//	printf(" Calc Time = %.6fms\n", time/ LOOP_COUNT);
	printf("%.6f\n", time / LOOP_COUNT);
}

BW Find_Best_Worst_DC(int array[], int start, int end){
	BW result, left, right;
	int mid;
	switch (end-start+1){
	case 1:
		result.worst = start;
		result.best = start;
		return result;
	case 2:
		if (array[start] < array[end]){
			result.worst = start;
			result.best = end;
		} else {
			result.worst = end;
			result.best = start;
		}
		return result;
	default:
		mid = floor((start + end) / 2);
		left = Find_Best_Worst_DC(array, start, mid);
		right = Find_Best_Worst_DC(array, mid + 1, end);
		if (left.worst < right.worst){
			result.worst = left.worst;
		} else {
			result.worst = right.worst;
		}
		if (left.best < right.best){
			result.best = right.best;
		} else {
			result.best = left.best;
		}
		return result;
	}
}
