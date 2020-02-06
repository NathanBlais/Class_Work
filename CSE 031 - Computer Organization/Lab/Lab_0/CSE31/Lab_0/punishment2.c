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

	printf("Enter the line for which we want to make a typo: ");
	int typo;
	scanf("%d", &typo);

	if (typo < 1){
		printf("You entered an incorrect value for the line typo!\n");
		return 0;
	}



	for (int i=0; i < number; i++){
		if (i == (typo - 1)){
		printf("C programming language is the bet! ");
		}
		else
		printf("C programming language is the best! ");
	}
	printf("\n");
	return 0;
}
