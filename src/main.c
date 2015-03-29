/*
 * main.c
 *
 *  Created on: 2015. 3. 26.
 *      Author: Administrator
 */

#include "selecting.h"

int *input;
// input array size
int data_size;
// random data set variable
double factor, max, min = 0.0;

int main(){
	int go, size, i;

	printf("\n\t\tSelect Menu");
	printf("\n\t1. Linear First Best Select");
	printf("\n\t2. Linear Second Best Select");
	printf("\n\t3. DC Second Best Select");
	printf("\n\t4. ALL Select");
	printf("\n\t");
	printf("\n\t");

	scanf("%d", &go);

	printf("input Array size (exponentiation of 2) : ");
	scanf("%d", &size);

	data_size = (int)pow(2,size);

	// Randomize data (int)(rand()*factor)%(int)pow(2,size)+1 ( 1~2^arraysize )
	max = pow(2, size); // set rand max size
	factor = (max - min) / RAND_MAX; // set rand max factor
	srand(time(NULL));
	// increse rand max number. using factor!!


	input = (int *)malloc(sizeof(int) * data_size);

	for (i = 0; i < data_size; i++){ // fill input data
		input[i] = i+1;
	}



	switch(go){
	case 1:
		linear_first();
		break;
	case 2:
		linear_second();
		break;
	case 3:
		dc_second();
		break;
	case 4:
		linear_first();
		linear_second();
		dc_second();
		break;
	}

	return 0;
}
