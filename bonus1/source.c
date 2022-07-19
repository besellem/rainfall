#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	char	buffer[40];
	int		n;
	
	n = atoi(argv[1]);
	if (n < 10)
	{
		memcpy(buffer, argv[2], n * 4);
		if (n == 0x574f4c46)
		{
			execl("/bin/sh", "sh", NULL);
		}
		return 0;
	}

	return 1;
}
