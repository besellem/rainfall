#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	v(void)
{
	char	str[520];

	fgets(str, 0x200, stdin);
	printf(str);
	if (m == 64)
	{
		fwrite("Wait what?!\n", 1, 0xc, stdout);
		system("/bin/sh");
	}
}

void	main(void)
{
	v();
	return;
}
