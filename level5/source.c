#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	o(void)
{
	system("/bin/sh");
	_exit(1);
}

void	n(void)
{
	char	str[520];

	fgets(str, 512, stdin);
	printf(str);
	exit(1);
}

int		main(void)
{
	n();
}
