#if _WIN32
	#include <windows.h>
#elif __linux__
	#include <time.h>
#endif
#include <stdio.h>
#include <string.h>


//Time in seconds.
void waitTime(double t)
{
	#if __linux__
	struct timespec t1;
	t1.tv_sec = (long)t;
	t = t - (long)t;
	t1.tv_nsec = (long)(t * 1e9);
	nanosleep(&t1, NULL);
	#elif _WIN32
	Sleep(t * 1000);
	#endif
}
void slowPrint(char *message, double writeInterval, int backSpace, double backSpaceInterval)
{
	int len = strlen(message);
	setvbuf(stdout, NULL, _IONBF, 0);
	for(int i=0;i<len;i++)
	{
		printf("%c", message[i]);
		waitTime(writeInterval);
	}
	setlinebuf(stdout);
	//remove the input slowly (looks like we are backspace-ing)
	if(backSpace == 1)
	{
		printf("\r");
		for(int i=len;i>=0;i--)
		{
			fflush(stdout);
			for(int j=0;j<i;j++)
				printf("%c", message[j]);
			waitTime(backSpaceInterval);
			printf("\r");
			for(int j=0;j<i;j++)
				printf(" ");
			printf("\r");
		}
	}
}
