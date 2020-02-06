#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	int num;										//Stack [Allocate] <- Stack C4[NO]
	int *ptr;										//Stack [Allocate] <- Stack C4[NO]
	int **handle;									//Stack [Allocate] <- Stack C4[NO]

	num = 14;										//Stack C4[NO]
	ptr = (int *)malloc(2 * sizeof(int));			//Heap and to a lesser point Stack [Allocate] <- Heap C4[NO]
	handle = &ptr;									//Stack C4[NO]
	*ptr = num;										//Heap C4[NO]
	ptr = &num;										//Stack  C4[YES]
	handle = (int **)malloc(1 * sizeof(int **));	//Heap and to a lesser point Stack [Allocate] <- Heap C4[NO]
} //Freed

