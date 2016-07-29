// read in .mbrq file -> story content
// read in dependencies -> locations, environments, objects, etc. 
// LOOP 
	// step through story
	// display options
	// process input
	// chance state


#include <stdio.h>
#include <stdlib.h>

FILE* openFile();

int main(){

	FILE *storyFile = openFile();

	fseek(storyFile, 0, SEEK_END); // seek to end of file
	int size = ftell(storyFile); // get current file pointer
	fseek(storyFile, 0, SEEK_SET);

	char* story = (char*) malloc(size * sizeof(char));
	int i = 0;
	do{
		*(story + i) = fgetc(storyFile);
		i++;
	}while(!feof(storyFile) && !ferror(storyFile));

	printf("%s\n", story);
	free(story);

	return 0;
}

FILE* openFile(){

	char* path = (char*) malloc (128 * sizeof(char));

	printf("Enter the path to the .mbrq file you'd like to open: ");
	scanf("%127s", path);

	FILE *fr = fopen(path, "r");                                
    if (fr == NULL) {
        printf("The file didn't open.\n");
        return 0;
    }

	free(path);
    return fr;

}