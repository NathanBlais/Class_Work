#include <stdio.h>
#define MAXSIZE 4096

/**
 * You can use this recommended helper function 
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */
char temp1[] = {"....."}; //for TESTING ONLY
 
 int rgrep_matches(char *line, char *pattern);
 
int matches_leading(char *partial_line, char *pattern) {
  // Implement if desire 
  
	if(*pattern == '\0'){
		return 1;
	}
    
    if (*(partial_line) == '\n'){
        return 0;
    }
	
	int slash = 0;
	if(*pattern == '\\'){ //Reads next character as a normal character
		/*char* debug = pattern+1;
		debug++;*/
		/*if(*(pattern+1) == '\\'){
			if(*(pattern+2) != '?' || *(pattern+2) != '+'){
				if(*(partial_line) != '\\'){
					return 0;
				}
				else
					return matches_leading(partial_line+1,pattern+2);
			}
			else{
				slash = 1;
				pattern = pattern + 2;
			}
		}
		else if(*(pattern+1) == '.'){
			if(*(pattern+2) != '?' || *(pattern+2) != '+'){
				if(*(partial_line) != '.'){
					return 0;
				}
				else
					return matches_leading(partial_line+1,pattern+2);
			}
			else{
				slash = 1;
				pattern = pattern + 2;
			}
		}*/
		
		if(*(pattern+1) == '\\' || *(pattern+1) == '.'){
			slash = 1;
			pattern++;
		}
		
		else if(slash != 1)
			return matches_leading(partial_line,pattern+1);
	}
	
	if(*(pattern+1) == '?'){
		int m = 0;
		
		if(*(pattern+2) == '\0'){
			return 1;
		}
		
		if(*partial_line == *pattern || (*pattern == '.' && slash != 1)){
			m = matches_leading(partial_line+1,pattern+2); //Assumes character exists
		}
		if(*partial_line == *(pattern+2) && m != 1){
			m = matches_leading(partial_line+1,pattern+3); //Assumes character doesn't exist
		}
		
		return m;
	}
	
	if(*(pattern+1) == '+'){
		
		if(!(*pattern == '.' && slash != 1) && *pattern != *partial_line){ //Check if first character exists
			return 0;
		}
		
		if(*(pattern+2) == '\0'){ //Check if the pattern continues
			return 1;
		}
		
		if(*pattern == '.' && slash != 1){
			return rgrep_matches((char*)(partial_line+1), (char*)(pattern + 2));
		}
		
		else{
			char match = *pattern;
			//int inc;
			pattern = pattern+2;
			while(*partial_line == *pattern){
				partial_line++;
				pattern++;
				//inc++;
			}
			while(*partial_line == match){
				partial_line++;
			}
			return matches_leading(partial_line, pattern);
		}
		
		/*else{
			int i;
			char* line = partial_line+1;
			while(*line !='\n'){
				if(matches_leading(line,pattern+2)){
				i = 1;
				break;
				}
				line++;
				i = 0;
			}
			if(i == 0){
				return 0;
			}
		}
		
		if(*pattern == *(pattern+2)){ //Check for plus extension edgecase 'a+a'
			pattern = pattern+2;
			partial_line++;
			while(*pattern == *(pattern+1)){
				pattern++;
				if(*(pattern+1) == '\0'){ //Check again if the pattern continues
					return 1;
				}
			}
			while(*(partial_line) == *pattern){
				partial_line++;
			}
			return matches_leading(partial_line,pattern+1);
		}
		else{
			while(*(partial_line+1) == *pattern){
				partial_line++;
			}
			return matches_leading(partial_line,pattern+2);
		}*/
	}
	
	if(((*pattern == '.' && slash != 1))||*pattern == *partial_line){ //Checks for normal characters and any characters
		return matches_leading(partial_line+1,pattern+1);
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
	
	if(line != NULL){
		while(*line !='\n'){
			if(matches_leading(line,pattern)){
				return 1;
			}
			line++;
		}
	}
    return 0;
}

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
