#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

char	c[68];

void	m(void)
{
	time_t	now;
	
	now = time(NULL);
	printf("%s - %d\n", c, now);
}

int		main(int argc, char **argv)
{
	int		*tab1;
	int		*tab3;
	FILE	*stream;

	tab1 = (int *)malloc(8);
	tab1[0] = 1;
	tab1[1] = malloc(8);

	tab3 = (int *)malloc(8);
	tab3[0] = 2;
	tab3[1] = malloc(8);

	strcpy((char *)tab1[1], argv[1]);
	strcpy((char *)tab3[1], argv[2]);

	stream = fopen("/home/user/level8/.pass", "r");
	fgets(c, 68, stream);
	
	puts("~~");
	return 0;
}
