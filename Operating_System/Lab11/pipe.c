// pipe.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

int main(){
	int parent_pipe[2]; // The parent process will write into this pipe
	int child_pipe[2]; // The child process will write into this pipe
	char buffer[BUFFER_SIZE]; // String variable to store messages
	int counter = 0;
	pid_t pid;
	if (-1 == pipe(parent_pipe)) // System Call to create a pipe variable
	{
		perror("Failed to create parent pipe");
		exit(1);
	}
	if (-1 == pipe(child_pipe)) // System Call to create a pipe variable
	{
		perror("Failed to create child pipe");
		exit(1);
	}
	pid = fork();
	switch(pid)
	{
		case -1:
			printf("Failed to create child process\n"); return -1;
		case 0:
			while(1) // Loop infinitely in child process
			{
				sprintf(buffer, "Message from child: %d", counter++);
				write(child_pipe[1], buffer, strlen(buffer)); // Write into child pipe
				memset(buffer, 0, BUFFER_SIZE); // Erase the string in the buffer
				read (parent_pipe[0], buffer, BUFFER_SIZE); // Read from parent pipe
				printf("Child received message: %s\n", buffer);
				sleep(1);
			}
		default:
			while(1) // Loop infinitely in parent process
			{
				sprintf(buffer, "Message from parent: %d", counter--);
				write(parent_pipe[1], buffer, strlen(buffer)); // Write into parent pipe
				memset(buffer, 0, BUFFER_SIZE); // Erase the string in the buffer
				read(child_pipe[0], buffer, BUFFER_SIZE); // Read from child pipe
				printf("Parent received message: %s\n", buffer);
				sleep(1);
			}
	}
}
