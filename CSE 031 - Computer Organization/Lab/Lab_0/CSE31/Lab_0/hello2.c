#include <stdio.h>
int main()
{
	printf("Please enter your name: ");
	char namef[30];
	//char namel[30];
	gets(namef);
	printf("Welcome to CSE031, %s!\n", namef);
	return 0;
}
