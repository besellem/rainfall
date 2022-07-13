#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	n(void)
{
	system("/bin/cat /home/user/level7/.pass");
}

void	m(void *param_1, int param_2, char *param_3, int param_4, int param_5)
{
	puts("Nope");
}

void	main(int argc, char **argv)
{
	char	*dest;
	void	**ptr;

	dest = (char *)malloc(64);
	ptr = (void **)malloc(sizeof(void *));
	*ptr = m;
	strcpy(dest, *(char **)(argv + 4));
	(**ptr)();
}
