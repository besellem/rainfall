#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	n(void)
{
	system("/bin/cat /home/user/level7/.pass");
}

void	m(void)
{
	puts("Nope");
}

int	main(int argc, char **argv)
{
	char	*dest;
	void	(*f)(void);

	dest = (char *)malloc(64);
	f = (void *)malloc(4);
	f = m;
	strcpy(dest, argv[1]);
	(*f)();
}
