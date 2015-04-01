/*
 * pivot.c
 *
 *  Created on: 2015. 4. 1.
 *      Author: Administrator
 */

#include "selecting.h"

void pivot(){
	extern int *input;
	int i, x, result;

	// input array size
	extern int data_size;

	// Time check variable
	double time;
	BOOL err;

	int copy_input[data_size];
	for (i = 0; i < data_size; i++){
		copy_input[i] = input[i];
	}

	CHECK_TIME_START;
//	for (x = 0; x < LOOP_COUNT; x++) {

		result = Find_Second_Max_DC(copy_input, 0, data_size);
//		if (x % (LOOP_COUNT / 10) == 0) printf("*");
//		printf("Selecting Result --> input[%d] : %d\n", result, input[result]);
//	}
	CHECK_TIME_END(time, err);

//	printf(" Calc Time = %.6fms\n", time/ LOOP_COUNT);
	printf("%.6f\n", time / LOOP_COUNT);
}

int Find_Second_Max_Pivot(int array[], int start, int end, int x){

	return 0;
}
