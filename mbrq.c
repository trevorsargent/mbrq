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

	int lines = 128;
	char** storyLines = (char**) malloc(lines * sizeof(char*));

	int i = 0;

	do{
		*(storyLines + i) = (char*) malloc(256 * sizeof(char));
		fgets(*(storyLines + i), sizeof(*(storyLines+i)), storyFile);
		i++;

		if(i == lines - 1){
			lines += 128;
			realloc(storyLines, lines);
		}

	}while(!feof(storyFile) && !ferror(storyFile));

	// printf("%s\n", story);
	// free(storyFile);

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