#include <stdio.h>
#include <dlfcn.h>
void *FunctionLib;

const char *dlErr;

int main()
{
	FunctionLib = dlopen("/home/kinten/Projects/Miura-Engine/")
	dlErr = dlerror();
	if (dlErr)
	{
		printf("Error: %s", dlErr);
		exit(1);
	}
}