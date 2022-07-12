#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	p(void)
{
	unsigned long	retaddr;
	char			buffer[76];

	fflush(stdout);
	gets(buffer);
	if ((retaddr & 0xb0000000) == 0xb0000000) {
		printf("(%p)\n", (void *)retaddr);
		_exit(1);
	}
	puts(buffer);
	strdup(buffer);
}

void	main(void)
{
	p();
	return;
}
