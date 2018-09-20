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
		fprintf(stderr, "File %s has not opened.", filename);
		exit(EXIT_FAILURE);
	}

	fgets(*buffer, size, input);

	fclose(input);	
	return size;
}

int write_file( char* filename, char *buffer, int size ){
	

	FILE *output = fopen(filename, "w");

	int i;
	for(i = 0; i < size ; i++){
		fprintf(output, "%c", buffer[i]);
	}

	fclose(output);
	return 0;
}
