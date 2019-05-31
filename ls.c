#include "ls.h"

void ls() {
	const char *directionPath = directionPath = getenv("PWD");
	if(directionPath == NULL) {
		printf("\n ERROR : Could not get the working directory\n");
		return;
	}
	DIR *directionCurrent  = opendir(directionPath);
	if(directionCurrent == NULL) {
		printf("\n ERROR : Could not open the working directory\n");
		return;
	}
	size_t count = 0;
	struct dirent *item = NULL;
	for(count = 0;(item = readdir(directionCurrent)) != NULL;count++) { 
		printf("%s\t",item->d_name);
	}
	printf("\n");
}
