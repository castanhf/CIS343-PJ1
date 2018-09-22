#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "file_utils.h"

int main(int argc, char* argv[]){

	int numByte;
	char *readDoc;
	char *writeDoc;
	char *writeBuffer;
	char **buf;
	
	readDoc = argv[1];

	writeDoc = argv[2];

	buf = &readDoc;

	numByte = read_file(readDoc, buf);

	writeBuffer = (char*)malloc(numByte * sizeof(char*));

	//reverse happens here
	for(int i = 0; readDoc[i] != '\0'; i++) {
	//	fprintf(writeDoc, "%c", buf[numByte - i - 1]);
		writeBuffer[i] = readDoc[numByte - i - 2];
	}
	

	write_file(writeDoc, writeBuffer, numByte);
	
	free(readDoc);
	free(writeBuffer);
	
	//make an exception here
	//check for memory leaks
	
	return 0;
}
