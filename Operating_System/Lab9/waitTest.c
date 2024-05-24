//waitTest.c
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
int main(){
	int counter=1;
	int status;
	pid_t pid;
	pid_t child_pid;
	pid=fork();
	switch(pid){
		case -1:
			printf("failed to create child process \n");
			return -1;
		case 0:
			printf("I am the child. I will exit after I count to 5 \n");
			while (6>counter){
				printf("child: %d\n", counter++);
				sleep(1);
			}
			return 99;
		default:
			printf("I am the parent. I will wait until the child process ends \n");
			child_pid=wait(&status);
			printf("child process with id %d finished ",child_pid);
			if (0==(status&0xff))
				printf("successfully. child exit status is %d\n", status>>8);
			else
				printf("unsuccessfully. child exit status is %d\n", status);
		        printf("I am the parent. now I will do my counting. \n");
			while(1){
				printf("parent: %d\n", counter++);
				sleep(1);
			}
	}
}

