/*
Nathan Blais
CSE 31-01
Homework #2
09/24/18
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** copyStrArray (int argc, char **argv);



int main () {
    int argc = 2;
    char A[] = {'H', 'E', 'L', 'L', '\0'};
    char B[] = {'L', 'E', 'N', 'T', '\0'};
    //char C[] = {'F', 'L'};
    char *argv[] = {A, B};
    //char **argv = argv_real;
  char **ptr;
  ptr = copyStrArray (argc, argv);

    
    printf("S1:\t%s\n",ptr[0]);
    printf("S2:\t%s\n",ptr[1]);
   // printf("S3:\t%s\n",ptr[2]);

return 0;
}

char** copyStrArray (int argc, char **argv){
	char **str = (char**)malloc(argc * sizeof(char *));
        for(int i = 0; i < argc; i++){
                str[i]= (char *) malloc((strlen(argv[i])+1) * sizeof(char *));
            strcpy(str[i] , argv[i]);
        }
    return str;
}
