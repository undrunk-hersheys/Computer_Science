//forkTest.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	int counter=0;
	pid_t pid;
	printf("creating child process\n");
	pid=fork();
	int i=5;
	int j=5;
	switch(pid){
		case -1:
			printf("failed to create child process\n");
			return -1;
			break;
		case 0:
			printf("count down in the child process \n");
			while(i){
				printf("child: %d\n", counter--);
				sleep(1);
				i--;
			}
			break;
		default:
			printf("count up in the parent process \n");
			printf("process ID of child process is %d. \n", pid);
			while(j){
				printf("parent: %d\n", counter++);
				sleep(1);
				j--;
			}
			break;
	}
}

