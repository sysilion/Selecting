

#include "selecting.h"

void linear_best_worst(){
	extern int *input;
	int x;

	int* result;

	// input array size
	extern int data_size;

	// Time check variable
	double time;
	BOOL err;

	CHECK_TIME_START;
//	for (x = 0; x < LOOP_COUNT; x++) {
		result = Find_Best_Worst(input, 0, data_size);

//		if (x % (LOOP_COUNT / 10) == 0) printf("*");
//		printf("Selecting Result --> input[%d] : %d, input[%d] : %d\n", result[0], input[result[0]], result[1], input[result[1]]);
//	}
	CHECK_TIME_END(time, err);

//	printf(" Calc Time = %.6fms\n", time / LOOP_COUNT);
	printf("%.6f\n", time / LOOP_COUNT);
}

int* Find_Best_Worst(int array[], int start, int end){
	int best = Find_Max(array, start, end);
	int worst = best;
	int result[2];
	for (; start < end && start != best; start++){
		if (array[start] < array[worst]){
			worst = start;
		}
	}
	result[0] = best;
	result[1] = worst;
	return result;
}
