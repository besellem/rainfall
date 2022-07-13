#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	if (atoi(av[1]) == 423)
	{
		char *s = strdup("/bin/sh");
		int egid = getegid();
		int euid = geteuid();
		setresgid(egid, egid, egid);
		setresuid(euid, euid, euid);
		execv("/bin/sh", &s);
	}
	else
	{
		fwrite("No !\n", 1, 5, stderr);
	}
	return 0;
}
