#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//#include <errno-base.h>
#include <sys/stat.h>
#include "file_utils.h"

int read_file( char* filename, char **buffer ){
	
	FILE *input;
	
	//gets size of the file
	//(only works in Linux)
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	*buffer = (char*)malloc(size * sizeof(char));

	input = fopen(filename, "r");

	if(input == NULL) {
		fprintf(stderr, "File %s has not opened to read.", filename);
		exit(-1);
	}

	fgets(*buffer, size, input);

	fclose(input);	
	return size;
}

int write_file( char* filename, char *buffer, int size ){
	

	FILE *output;
       
	output = fopen(filename, "w");

	if(output == NULL) {
		fprintf(stderr, "File %s has not opened to write.", filename);
		exit(-1);
	}

	int i;
	for(i = 0; i < size ; i++){
		fprintf(output, "%c", buffer[i]);
		printf("%c", buffer[i]);
	}

	fclose(output);
	return 0;
}
