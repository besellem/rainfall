#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	run(void)
{
	fwrite("Good... Wait what?\n", 1, 19, stdout);
	system("/bin/sh");
}

void	main(void)
{
	char	s[76];
	
	gets(s);
}
