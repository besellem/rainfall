#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		m;

void	p(char *str)
{
	printf(str);
}

void	n(void)
{
	char	str[520];

	fgets(str, 512, stdin);
	p(str);
	if (m == 16930116)
	{
		system("/bin/cat /home/user/level5/.pass");
	}
}

int		main(void)
{
	n();
}
