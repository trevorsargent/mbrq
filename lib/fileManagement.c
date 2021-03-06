#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataStructures.h"

Waypoint* readFile(FILE* fp) {
	int size = 128;
	int numPoints = 0;
	Waypoint* wp = (Waypoint*) malloc(size * sizeof(Waypoint));

	char line[256], param[128], value[128];
	char* trimmed;
	char* token;
	char delim[2] = ":";
	
	do {

		// read in the line
		fgets(line, sizeof(line), fp);

		// trim the trailing newline character off the line
		trimmed = strtok(line, "\n");

		// split based on ":"
		token = strtok(line, delim);

		//as long as there's something in the token....
		while (token != NULL) {

			if (strcmp(token, ">>>") == 0) {
				// new Waypoint

			} else if (strcmp(token, "<<<") == 0) {
				// done with the Waypoint
				numPoints++;

				// grow memory if necessary
				if ((size - numPoints) < 2) {
					size += 128;
					wp = realloc(wp, size * sizeof(Waypoint));
				}

			} else if (strcmp(token, "name") == 0) {
				// reading name
				token = strtok(NULL, delim);
				strcpy(wp[numPoints].name, token);	

			} else if (strcmp(token, "environment") == 0) {
				// reading environment
				token = strtok(NULL, delim);
				strcpy(wp[numPoints].environment, token);		

			} else if (strcmp(token, "time") == 0) {
				// reading time 
				token = strtok(NULL, delim);
				wp[numPoints].time = atoi(token);	

			} else if (strcmp(token, "optionA") == 0) {
				// reading optionA
				token = strtok(NULL, delim);
				strcpy(wp[numPoints].options[0], token);

			} else if (strcmp(token, "optionB") == 0) {
				// reading optionB
				token = strtok(NULL, delim);
				strcpy(wp[numPoints].options[1], token);

			} else if (strcmp(token, "optionC") == 0) {
				// reading optionC
				token = strtok(NULL, delim);
				strcpy(wp[numPoints].options[2], token);	

			} else if (strcmp(token, "optionAPath") == 0) {
				// reading optionAPath
				token = strtok(NULL, delim);
				wp[numPoints].optionPaths[0] = atoi(token);	

			} else if (strcmp(token, "optionBPath") == 0) {
				// reading optionBPath
				token = strtok(NULL, delim);
				wp[numPoints].optionPaths[1] = atoi(token);		

			} else if (strcmp(token, "optionCPath") == 0) {
				// reading optionCPath
				token = strtok(NULL, delim);
				wp[numPoints].optionPaths[2] = atoi(token);	

			}

			// consume any last data in the line (mostly to confirm that it is empty)
			token = strtok(NULL, delim);

		}

	// continue till end of file
	} while (!feof(fp) && !ferror(fp));

	return wp;
}

FILE* openFile() {

	char* storyName = (char*) malloc (128 * sizeof(char));

	printf("Enter the name of the story you'd like to read: ");
	scanf("%127s", storyName);

	char pkgext[7] = ".mbrq/";
	char stryext[7] = ".story";
	char path[1024];

	strcat(path, storyName);
	strcat(path, pkgext);
	strcat(path, storyName);
	strcat(path, stryext);

	FILE *fr = fopen(path, "r");
	if (fr == NULL) {
		printf("The file didn't open.\n");
		return 0;
	}
	return fr;

}

FILE* openFilePath(char *storyName){


	char pkgext[7] = ".mbrq/";
	char stryext[7] = ".story";
	char path[1024];

	strcat(path, storyName);
	strcat(path, pkgext);
	strcat(path, storyName);
	strcat(path, stryext);

	FILE *fr = fopen(path, "r");
	if (fr == NULL) {
		printf("The file didn't open.\n");
		return 0;
	}

	return fr;

}