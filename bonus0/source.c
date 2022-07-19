#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	p(char *s, char *header)
{
	char	*ptr;
	char	buf[4104];

	puts(header);
	read(0, buf, 4096);

	ptr = strchr(buf, '\n');
	*ptr = '\0';

	strncpy(s, buf, 20);
}

void	pp(char *buffer)
{
	char	s1[20];
	char	s2[20];

	p(s1, " - ");
	p(s2, " - ");

	strcpy(buffer, s1);
	buffer[strlen(buffer)] = ' ';

	strcat(buffer, s2);
}

int		main(void)
{
	char	buffer[54];

	pp(buffer);
	puts(buffer);
	return 0;
}
