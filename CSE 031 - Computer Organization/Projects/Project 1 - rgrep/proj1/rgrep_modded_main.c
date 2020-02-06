#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 4096

/**
 * You can use this recommended helper function 
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */

char temp1[] = {"\\\\"}; //for TESTING ONLY   ''+.\\'

int rgrep_matches(char *line, char *pattern);

int rgrep_matches_without_reverse(char *line, char *pattern);

void myMemCpy(void *dest, void *src, size_t n) /*myMemCpy was taken from https://www.geeksforgeeks.org/write-memcpy/ */
{
    // Typecast src and dest addresses to (char *)
    char *csrc = (char *)src;
    char *cdest = (char *)dest;
    
    // Copy contents of src[] to dest[]
    for (int i=0; i<n; i++)
        cdest[i] = csrc[n - i - 1]; //modified to swich the order
}

int matches_leading(char *partial_line, char *pattern) {
    
//recursion check
    if (*pattern == '\0')
        return 1;
    
    if ( *partial_line == '\n' || *partial_line == '\0'){
        if (*(pattern) == '?'){
            return 1;
        }
        else
            return 0;
    }
//special characters
    if (*pattern == '.' || *(pattern) == '+' || *(pattern) == '?' || *(pattern + 1) == '\\'){
        
        //assign the flag
        char flag = '\0';
        if(*(pattern + 1) == '\\')
            flag = *(pattern + 1);
        else if(*(pattern) == '+' || *(pattern) == '?' || *pattern == '.')
            flag = *(pattern);
        
        switch(flag){
            case '.' :
                return(matches_leading(partial_line + 1, pattern + 1));
                return 0;
                break;
            case '+' :
            
                if (*(pattern + 1) == '.' && *(pattern + 2) != '\\') {      //The input wound be '.+'
                    return(rgrep_matches_without_reverse(partial_line, pattern + 1));
                }
                else if (*(pattern + 1) == '+' && *(pattern + 2) != '\\') {      //The input wound be '.+'
                    ;
                }
                else if (*(pattern + 1) == '?' && *(pattern + 2) != '\\'){ //The input wound be '?+'
                    
                    if (*(partial_line) == *(pattern + 2)) //if the next character is there
                        ;
                    else                                   //if the next character is not there
                        return(matches_leading(partial_line, pattern + 3));
                    
                    
                    
                    printf("is '?+' possible?\n"); // ?+ is seen as +? on stack
                    return 0;
                }
                else if(*partial_line != *(pattern + 1)) //if the first characters don't match
                    return 0;
                
               /* char pat[MAXSIZE] = {pattern[0]}; //Make a new pattern without the '+'
                char *line = pattern + 2;
                for (int k =1; *line != '\0'; k++){
                    pat[k] = *line;
                    line = line+1;
                }
                
                return(rgrep_matches_without_reverse(partial_line, pat));
                
                */
                
                
                char holder = *partial_line;
                int counter = 0;
                while(*partial_line == holder){
                    partial_line++;
                    counter++;
                }
                return (matches_leading(partial_line, pattern + 3));
                
                break;
            case '?' :
                if (*pattern == '.')       //The input wound be '.?'
                    ;//do nothing
                else if (*pattern == '+'){ //The input wound be '+?'
                    printf("is '+?' possible?\n");
                    return 0;
                }

                if (*(pattern + 1) == *(pattern + 2)){ //if there is multiple of one character followoing, in patern, ex. 'aa?a'
                    int counterP = 0, counterL = 0;
                    char *l_T = partial_line;
                    char *p_T = pattern + 1;
                    while(*l_T == *partial_line){//counts number of imidately following repeated characters for Line
                        counterL++;
                        l_T++;
                    }
                    while(*p_T == *(pattern + 1)){//counts number of imidately following repeated characters for Pattern
                        counterP++;
                        p_T++;
                    }
                    
                    if(counterP == counterL){
                        return(matches_leading(partial_line + 1, pattern + 2));//???
                    }
                    else if(counterP - 1  == counterL){
                        return(matches_leading(partial_line, pattern + 2));
                    }
                    else //
                        return 0;
                }
                
                // else{                              //if there is a diffrent character followoing, in patern, ex. 'a?b'
                if (*(partial_line) == *(pattern + 1)) //if the next character is there
                    return(matches_leading(partial_line + 1, pattern + 2));
                else                                       //if the next character is not there
                    return(matches_leading(partial_line, pattern + 2));
                // }
                break;
            case '\\' :
                
                
                if (*(pattern) == '+' && *(pattern + 2) == '\\') {
                    if(*partial_line != *(pattern + 2)) //if the first characters don't match
                        return 0;
                    char holder = *partial_line;
                    int counter = 0;
                    while(*partial_line == holder){
                        partial_line++;
                        counter++;
                    }
                    return (matches_leading(partial_line, pattern + 3));
                }
                
                if (*(pattern) == '?' && *(pattern + 2) == '\\') {
                    
                    ;//Fill if you have time
                }
                if (*partial_line == *(pattern))
                    return(matches_leading(partial_line + 1, pattern + 2));
                else
                    return 0;
                
                break;
            default :
                printf("Error with switch\n" );
                return 0;
        }
        
    }
    
    
    //normal characters
    
    //if((*pattern >= 'A' && *pattern <= 'Z') || (*pattern >= 'a' && *pattern <= 'z')){ // if the current character ==
    if (*partial_line == *pattern)
        return(matches_leading(partial_line + 1, pattern + 1));
    else
        return 0;
    //}
    
    
    //? Use Recursive for this
    // Implement if desire
    
    printf("ERROR: hit end of special char\n");
    return 0;//temporarry
}

int rgrep_matches_without_reverse(char *line, char *pattern) {
    while (*line != '\0' || *line != '\n'){
        
        if(matches_leading(line,pattern))
            return 1;
        line = line+1;
    }
    return 0;
}

/**
 * You may assume that all strings are properly null terminated
 * and will not overrun the buffer set by MAXSIZE
 *
 * Implementation of the rgrep matcher function
 */
int rgrep_matches(char *line, char *pattern) {
    
    
    ///////////////////////// FOR LINE /////////////////////////
    char *line_shallow = line;
    size_t char_counter = 0;
    
    while (*line_shallow != '\0' && *line_shallow != '\n'){ //counter for number of characters
        char_counter++;
        line_shallow++;
    }
    char* line_stack = (char*)malloc(sizeof(char)* char_counter + 1); //asignes memory
    
    myMemCpy(line_stack,line,char_counter);
    
    ///////////////////////// FOR PATTERN /////////////////////////
    
    char *pat_shallow = pattern;
    char_counter = 0;
    
    while (*pat_shallow != '\0' && *pat_shallow != '\n'){ //counter for number of characters
        char_counter++;
        pat_shallow++;
    }
    char *pat_stack = (char*)malloc(sizeof(char)* char_counter + 1); //asignes memory
    
    myMemCpy(pat_stack,pattern,char_counter);
    
    ///////////////////////// FOR LOOP /////////////////////////
    
    while (*line_stack != '\0' && *line_stack != '\n'){
        
        if(matches_leading(line_stack,pat_stack)){
            return 1;
        }
        line_stack = line_stack + 1;
    }
    return 0;
    
    // ? Use Recursive for this
    // Implement me
}

// **TEMPOEARY FOR TESTING***  int main(int argc, char **argv) { *** PUT BACK WHEN DONE***
int main(){
    
    int argc = 2;// FOR TESTING ONLY DELEATE WHEN DONE
    //char temp1[] = {""};
    
    char *argv[] = {temp1,temp1};
    
    FILE *fp;
    fp = fopen( "/Users/NathanBlais/Dropbox/`School/UCM/Fall_2018/CSE_31_Computer_Organization/Projects/Project1/Project1/short.txt", "r" );
    
     // FOR TESTING ONLY DELEATE WHEN DONE

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PATTERN>\n", argv[0]);
        return 2;
    }

    /* we're not going to worry about long lines */
    char buf[MAXSIZE];

    while (!feof(fp) && !ferror(fp)) {
        if (!fgets(buf, sizeof(buf), fp)) {
            break;
        }
        if (rgrep_matches(buf, argv[1])) {
            fputs(buf, stdout);
            fflush(stdout);
        }
    }

    if (ferror(fp)) {
        perror(argv[0]);
        return 1;
    }

    return 0;
}
