#include <stdio.h>
#include <stdlib.h>
#include <config.h>

int main(int argc, char * argv[])
{
	printf("[%s] Hello from %s!\n", PACKAGE_NAME, argv[0]);
	return 0;
}

