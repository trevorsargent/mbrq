typedef struct {

	char environment[100];
	int time;

	char name[100];
	char text[256];
	char options[3][256];
	int optionPaths[3];

} Waypoint;