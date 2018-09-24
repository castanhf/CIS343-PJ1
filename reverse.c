#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "file_utils.h"

int main(int argc, char* argv[]){

	//variable of type int
	int numByte;

	//char pointers
	char *readDoc;
	char *writeDoc;
	char *writeBuffer;

	//pointer the a (char) pointer
	char **buf;
	
	//This char pointer stores the first argument
	//in the command line after the executable
	readDoc = argv[1];

	//This char pointer stores the second argument
	//in the command line after the executable
	writeDoc = argv[2];

	//pointer to a (char) pointer stores the
	//memory location of readDoc, which is a
	//char pointer
	buf = &readDoc;

	//numByte stores the size of a file after
	//the execution of read_file method
	numByte = read_file(readDoc, buf);

	//Memory allocation
	//writeBuffer gets borrows memoery from heap
	//for future file writings
	writeBuffer = (char*)malloc(numByte * sizeof(char*));
	if(writeBuffer == NULL) {
		fprintf(stderr, "Insufficient memory! Make a memory allocation!\n");
		exit(EXIT_FAILURE);
	}	

	//Reverse happens here
	//Reversed array of chars are stored
	//in char pointer writeBuffer
	for(int i = 0; readDoc[i] != '\0'; i++) {
		writeBuffer[i] = readDoc[numByte - i - 2];
	}
	
	//The writing of the reversed array of chars
	//into a file
	write_file(writeDoc, writeBuffer, numByte);
	
	//Maintenance of the borrowed memory
	//from the heap
	free(readDoc);
	free(writeBuffer);
	
	//make an exception here
	//check for memory leaks
	
	return 0;
}
