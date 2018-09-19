#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "file_utils.h"

int main(int argc, char** argv){

	int numByte;
	char *readDoc;
	char *writeDoc;
	char **buf = &readDoc;

	/*
	printf("Please input a file");
	scanf("%c", readDoc);
	printf("You entered: %c.\n Soon the contents will be reversed.", readDoc);
	*/	

	numByte = read_file(readDoc, buf);
	
	//reverse happens here
	for(int i = 0; *buf[i] != '\0'; i++) {
	//	fprintf(writeDoc, "%c", buf[numByte - i - 1]);
		writeDoc[i] = *buf[numByte - i - 1];
	}
	

	write_file(readDoc, writeDoc, numByte);
	
	free(buf);
	
	//make an exception here
	//check for memory leaks
	
	return 0;
}
