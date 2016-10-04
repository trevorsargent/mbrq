#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/fileManagement.h"

int main(int argc, char *argv[]) {

	FILE *storyFile;

	if (argc == 1){
		storyFile = openFile();
	}else{
		storyFile = openFilePath(argv[1]);
	}


	Waypoint* wp = readFile(storyFile);

	return 0;
}

