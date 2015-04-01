/*
 * linear_second.c
 *
 *  Created on: 2015. 3. 26.
 *      Author: Administrator
 */

#include "selecting.h"

void linear_second(){
	extern int *input;
	int x, result;

	// input array size
	extern int data_size;

	// Time check variable
	double time;
	BOOL err;

	CHECK_TIME_START;
	for (x = 0; x < LOOP_COUNT; x++){
		result = Find_Second_Max(input, 0, data_size);

//		if(x%(LOOP_COUNT/10) == 0) printf("*");
//		printf("Selecting Result --> input[%d] : %d\n", result, input[result]);
	}
	CHECK_TIME_END(time, err);

//	printf(" Calc Time = %.6fms\n", time/LOOP_COUNT);
	printf("%.6f\n", time / LOOP_COUNT);
}

int Find_Second_Max(int array[], int start, int end){
	int second_max = start, max = Find_Max(array, start, end);
	for (start++; start < end; start++){
		if (array[start] > array[second_max] && start != max){
			second_max = start;
		}
	}
	return second_max;
}
