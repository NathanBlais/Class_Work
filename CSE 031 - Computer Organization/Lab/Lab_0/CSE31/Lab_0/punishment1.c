#include <stdio.h>

int main()
{
	printf("Enter the number of lines for the punishment: ");
	int number;
	scanf("%d", &number);
	if (number < 1){
		printf("You entered an incorrect value for the number of lines!\n");
		return 0;
	}
	for (int i=0; i < number; i++){
		printf("C programming language is the best! ");
	}
	printf("\n");
	return 0;
}
