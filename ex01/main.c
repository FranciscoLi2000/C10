#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024
#define FILES 100

int	main(int argc, char **argv)
{
	FILE	*fp[FILES];
	char	str[SIZE];
	int	i;

	if (argc < 2)
	{
		while (fgets(str, SIZE, stdin) != NULL)
			fputs(str, stdout);
		return (0);
	}
	i = 1;
	while (i < argc && i < FILES)
	{
		fp[i] = fopen(argv[i], "r");
		if (!fp[i])
		{
			fprintf(stderr, "%s: %s: No such file or directory.\n", argv[0], argv[i]);
			exit(1);
		}
		while (fgets(str, SIZE, fp[i]) != NULL)
			fputs(str, stdout);
		fclose(fp[i]);
		i++;
	}
	if (i < argc)
	{
		fprintf(stderr, "%s: Too many files, maximum is %d.\n", argv[0], FILES);
		exit(1);
	}
	return (0);
}
