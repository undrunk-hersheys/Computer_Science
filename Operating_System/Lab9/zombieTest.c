//zombieTest.c
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	pid_t child_pid;
	child_pid = fork();
	if (child_pid<0)
		exit(1);
	if (child_pid>0)
		sleep(60);
	else
		exit(0);
}
