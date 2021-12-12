#include "includes/cub3D.h"

int print_error(int errnum)
{
	printf("Error\n");
	if (errnum == 0)
		printf("Not enough argument (2 needed)\n");
	else if (errnum == 1)
		printf("File .cub has no name\n");
	else if (errnum == 2)
		printf("File has not the good extension (.cub required)\n");
	else if (errnum == 3)
		printf("File .cub is a directory\n");
	else if (errnum == 4)
		printf("File could not be open\n");
	else if (errnum == 5)
		printf("Textures or color missing\n");
	else if (errnum == 6)
		printf("Invalid char in map\n");
	else if (errnum == 7)
		printf("Too many coordinates\n");
	else if (errnum == 8)
		printf("Start position missing\n");
	else if (errnum == 9)
		printf("Hole in the outline\n");
	return (1);
}

