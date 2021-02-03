//This is cross-platform ..(cough) only windows and linux.. (cough)..

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
	//This is for sleep in linux.
	#if _WIN32
	Sleep(t * 1000);
	//This is for sleep in windows.
	#else
	struct timespec t1;
	t1.tv_sec = (long)t;
	t = t - (long)t;
	t1.tv_nsec = (long)(t * 1e9);
	nanosleep(&t1, NULL);
	#endif
	//And no one cares about apple, although it should work without a problem cuz oonix.
}

void slowPrint(char *message, double writeInterval, int backSpace, double backSpaceInterval)
{
	/*
		double writeInterval is the sleep time used while printing characters. Larger this number, slower the printing
		int backSpace should be set to 1 if you want to use the backspace effect.
		double backSpaceInterval is the sleep time used while removing characters(works if int backSpace is set to 1). Larger this number, slower is the removing
	*/

	int len = strlen(message);
	//Make the output stream unbuffered for printing instantly.
	setvbuf(stdout, NULL, _IONBF, 0);
	//do the typing thing.
	for(int i=0;i<len;i++)
	{
		printf("%c", message[i]);
		waitTime(writeInterval);
	}
	//reset the output stream to line buffered.
	setlinebuf(stdout);
	
	if(backSpace == 1)
	{
		//remove the input slowly (looks like we are backspace-ing)
		printf("\r"); //carriage return makes the cursor back to the first place in line.
		for(int i=len;i>=0;i--)
		{
			fflush(stdout);
			for(int j=0;j<i;j++)
				printf("%c", message[j]);
			waitTime(backSpaceInterval);
			printf("\r");
			//we need to clear the line, so we fill it with spaces.
			for(int j=0;j<i;j++)
				printf(" ");
			printf("\r");
		}
	}
}
