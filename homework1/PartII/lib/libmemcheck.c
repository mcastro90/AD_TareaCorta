#define _GNU_SOURCE

#include <dlfcn.h>

#include <stdio.h>
#include <stdlib.h>

long long mallocCallNum = 0;
long long freeCallNum = 0;

void* (*malloc_real)(size_t) = NULL;
void (*free_real)(void*) = NULL;

void __attribute__((constructor)) init_hooking()
{
	malloc_real = dlsym(RTLD_NEXT, "malloc");
	free_real = dlsym(RTLD_NEXT, "free");
}

void __attribute__((destructor)) finish_hooking()
{
	printf("Analysis finished!\n");
	printf("Memory allocations: %lld \n", mallocCallNum);
	printf("Memory free: %lld \n", freeCallNum);
	printf("Total memory leaks found: %lld \n", mallocCallNum - freeCallNum);
}

void* malloc(size_t size)
{
	void* ret = malloc_real(size);

    if (ret) {
        ++mallocCallNum;
    }

    return ret;
}

void free(void *ptr)
{
	if (ptr == NULL) {
        return;
    }

	free_real(ptr);
    ++freeCallNum;
}
