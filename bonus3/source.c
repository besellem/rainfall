#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	char	pass[16] = {0};
	char	buffer[66];
	FILE	*f;

	f = fopen("/home/user/end/.pass", "r");
	if ((f == NULL) || (argc != 2))
		return -1;

	fread(pass, 1, 66, f);
	pass[atoi(argv[1])] = 0;

	fread(buffer, 1, 65, f);
	fclose(f);

	if (strcmp(pass, argv[1]) == 0)
		execl("/bin/sh", "sh", NULL);
	else
		puts(buffer);

	return 0;
}
