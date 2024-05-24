//idTest.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void){
	printf("My Proccess ID is %ld\n", (long)getpid());
	printf("My Parent's Process ID is %ld\n", (long)getppid());
}

