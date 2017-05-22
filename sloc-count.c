#include <stdio.h>
typedef int bool;
#define true 1
#define false 0

//Rules: counts semicolon statements,non-blank and non-comment lines, ignores right braces and counts left braces

void main(){
        
        FILE *fp;
	char filename[400];
	char readline[400];
        int level= 0;
        int countline =0;
        int sloc=0;
	int previous=0;
        int comment=0;
	int levelnumber [400] = { 0 }; 
     //   int left=0, right =0;
	
	printf("Enter the name of file name\n");
        //get user input
        gets(filename);

        //open the file for reading
        fp = fopen(filename, "r");
	
	//for each line of the input file
	while (fgets(readline, 400, fp) != NULL) {
                //count total number of lines
		countline++; 
		// for each line
          for (int i = 0; readline[i] != '\n'; i++) {
                
		//for each non-whitespace characters	
		if (readline [i] != ' ') {
				
		//dealing with two types of command lines
		if (readline[i] == '/' && previous == '/') {
                              // when (//) is detected
				previous = 0;
				break;

		 } else if (readline[i] == '/' && previous =='*'){
                              //  when(*/)detected
					comment = false;
				 
				
		 }else if (readline[i] == '*' && previous == '/'){
                              //  when(/*)detected
					comment = true;
                
                 }
                       //save the previous token
			previous = readline[i];
				
		 
	         if (comment == false){
	                //count the number of semicolons as SLOC
			if (readline[i] == ';'){
				sloc++;
		        }else if (readline[i] == '{'){
                        //enter level and increment
                        //count left braces as a line
			        
			        levelnumber[level++]++;
		                sloc++;
                                
		        }else if (readline[i] == '}'){
                        //exit level and deincrement
//does not count right braces as SLOC--it pairs up with the left braces
 
			        level--;                                
		        }
		 }
		}
	  }
	}
 
	// printf("comment: %d\n", comment);
    printf("Total number of lines in the file: %d\n", countline);
    printf("Number of sloc: %d\n", sloc);

    printf("Number of scopes in each level: \n");
     
    //print scope and its contained value
    for ( int i=0; i <= 100 && levelnumber[i]!=0; i++){
          
         printf ("Level %d: ",i);
         printf("%d\n", levelnumber[i]);      
       
    } 
}
