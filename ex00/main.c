#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int	main(int argc, char **argv)
{
	FILE	*fp;
	char	str[SIZE];

	if (argc < 2)
	{
		fprintf(stderr, "File name missing.\n");
		exit(1);
	}
	if (argc > 2)
	{
		fprintf(stderr, "Too many arguments.\n");
		exit(1);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Cannot read file.\n");
		exit(1);
	}
	while ((fgets(str, SIZE, fp) != NULL) && (str != '\0'))
		fputs(str, stdout);
	return (0);
}
