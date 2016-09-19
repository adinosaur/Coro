
#include "Coro.h"
#include <stdio.h>
#include <assert.h>

void co1(void* msg)
{
	for (int i = 0; i != 5; ++i)
	{
		printf("%s\n", (char*)msg);
		coro_yield();
	}
}

int main(int ac, char** av)
{
	assert(sizeof(void*) == sizeof(unsigned long));
	
	coro_new(co1, "hello");
	coro_new(co1, "world");
	coro_main();
	return 0;
}