#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap (int *px, int *py) {
              int *temp;
              *temp = *px;
              *px = *py;
              *py = *temp;
}

void proc(){
    int x = 0;
}

int main () {
	int a = 1, b = 2;
	proc();
	swap(&a, &b);
    return 0;
}
