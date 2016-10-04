#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/fileManagement.h"

int main() {

	FILE *storyFile = openFile();

	Waypoint* wp = readFile(storyFile);

	return 0;
}

