#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include "file_utils.h"

int read_file( char* filename, char **buffer ){
	
	//File pointer
	FILE *input;
	
	//The following three lines of code get
	//get the size of the file
	//(only works in Linux)
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	//memory allocation from the heap in order
	//to read a file
	*buffer = (char*)malloc(size * sizeof(char));
	if(*buffer == NULL) {
		fprintf(stderr, "Insufficient memory available! Make a memory allocation!\n");
		exit(EXIT_FAILURE);
	}


	//pointer input is assigned with a file,
	//which is opened in read mode
	input = fopen(filename, "r");

	//Exception handling
	//Checks if file was opened correctly
	//Otherwise report error
	if(input == NULL) {
		fprintf(stderr, "File %s has not opened to read.\n", filename);
		exit(EXIT_FAILURE);
	}

	//Process of reading the file
	fgets(*buffer, size, input);


	//Closes the file
	fclose(input);	
	return size;
}

int write_file( char *filename, char *buffer, int size ){
	
	//File pointer
	FILE *output;
       
	//pointer output is assigned a file,
	//which is opened to write
	//(if file does not exist, then it will create
	//a new one)
	output = fopen(filename, "w");

	//Exception handling
	//Checks if file was opened correctly
	if(output == NULL) {
		fprintf(stderr, "File %s has not opened to write.\n", filename);
		exit(EXIT_FAILURE);
	}

	//Process of writing the file
	fwrite(buffer, 1, size, output);

	//Closes the file
	fclose(output);
	return 0;
}
