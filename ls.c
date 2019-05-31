#include "ls.h"

// pwd
unsigned char pwd(char *directionPath) {
	directionPath = getenv("PWD");
	// printf("==>%s\n", directionPath);
	if(directionPath == NULL) {
		// printf("Error: Could not get the working directory!\n");
		// return;
		return 0;
	}
	return 1;
}

// readDir
unsigned char readDir(char** directionPath, DIR *directionCurrent) {
	// printf("==>%s\n", directionPath);
	directionCurrent = opendir(*directionPath);
	if(directionCurrent == NULL) {
		// printf("Error: Could not open the working directory!\n");
		// return;
		return 0;
	}
	return 1;
}

// ls
void ls() {
	char *directionPath;
	unsigned char result;

	result = pwd(directionPath);
	if(result == 0) {
		printf("Error: Could not get the working directory!\n");
		return;
	}

	printf("==>%s\n", directionPath);

	DIR *directionCurrent;
	result = readDir(&directionPath, directionCurrent);
	if(result == 0) {
		printf("Error: Could not open the working directory!\n");
		return;
	}

	size_t count = 0;
	struct dirent *item = NULL;
	for(count = 0;(item = readdir(directionCurrent)) != NULL;count++) { 
		printf("%s\t",item->d_name);
	}
	printf("\n");
}
