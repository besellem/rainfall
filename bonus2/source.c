#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int		language;

void	greetuser(char *buffer)
{
	char	msg[20];

	if (language == 1)
		strcpy(msg, "Hyvää päivää ");
	else if (language == 2)
		strcpy(msg, "Goedemiddag! ");
	else if (language == 0)
		strcpy(msg, "Hello! ");

	strcat(msg, buffer);
	puts(msg);
}

int		main(int argc, char **argv)
{
	char	buffer[72];
	char	*lang;

	if (argc == 3)
	{
		strncpy(buffer, argv[1], 40);
		strncpy(buffer + 40, argv[2], 32);

		lang = getenv("LANG");
		if (lang != NULL)
		{
			if (memcmp(lang, "fi", 2) == 0)
				language = 1;
			else if (memcmp(lang, "nl", 2) == 0)
				language = 2;
		}

		greetuser(buffer);

		return 0;
	}

	return 1;
}
