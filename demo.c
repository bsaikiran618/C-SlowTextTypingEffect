#include "SlowText.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	//Printing in the same line
	for(int i=1;i<argc; i++)
	{
		char *message = argv[i];
		slowPrint(message, 0.1, 1, 0.05);
	}
	//Printing in different lines.
	for(int i=1;i<argc;i++)
	{
		char *message = argv[i];
		slowPrint(message, 0.1, 0, 0);
		printf("\n");
	}
	//Printing without backspace
	for(int i=1;i<argc;i++)
	{
		char *message = argv[i];
		slowPrint(message, 0.1, 0, 0);
		printf(" ");
	}
	printf("\n");
	return 0;
}
