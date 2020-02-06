/*
Nathan Blais
CSE 31-01
Homework #2
09/24/18
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


copyStrArray (argc, argv);

int main (int argc, char **argv) {
  char **ptr;
  ptr = copyStrArray (argc, argv);

return 0;
}

char* copyStrArray (int argc, char **argv){
	char *data_pointer = (char*)malloc(1 * sizeof(argv));

        for(int i = 0; i < argc; i++){
            data_pointer[i] = (*argv)[i];
        }



}