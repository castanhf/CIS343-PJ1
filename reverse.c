#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "file_utils.h"

int main(int argc, char* argv[]){

	int numByte;
	char *readDoc;
	char *writeDoc;
	char **buf = &readDoc;
	
	readDoc = argv[1];

	writeDoc = argv[2];

	numByte = read_file(readDoc, buf);
	
	//reverse happens here
	for(int i = 0; *buf[i] != '\0'; i++) {
	//	fprintf(writeDoc, "%c", buf[numByte - i - 1]);
		writeDoc[i] = readDoc[numByte - i - 1];
		printf("%c", writeDoc[i]);
	}
	

	write_file(writeDoc, *buf, numByte);
	
	free(buf);
	
	//make an exception here
	//check for memory leaks
	
	return 0;
}
