#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	p(void)
{
	void	*retaddr;
	char	buffer[76];

	fflush(stdout);
	gets(buffer);

	retaddr = __builtin_return_address (0);
	if (((unsigned int)retaddr & 0xb0000000) == 0xb0000000) {
		printf("(%p)\n", retaddr);
		_exit(1);
	}
	
	puts(buffer);
	strdup(buffer);
}

int		main(void)
{
	p();
}
