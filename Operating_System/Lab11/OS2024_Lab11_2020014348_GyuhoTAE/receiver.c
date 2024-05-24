// receiver.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO_FILE "/tmp/fifo1"
#define BUFFER_SIZE 1024

int main(void)
{
	int counter = 0;
	int fd; // file descriptor
	char buffer[BUFFER_SIZE];
	if (-1 == mkfifo(FIFO_FILE, 0666))
	{
		perror("Error making FIFO");
		exit(1);
	}
	if (-1 == (fd = open(FIFO_FILE, O_RDWR)))
	{
		perror("Error opening FIFO");
		exit(1);
	}
	while(1) // Loop infinitely
	{
		memset(buffer, 0, BUFFER_SIZE);
		read (fd, buffer, BUFFER_SIZE);
		printf("%d %s\n", counter++, buffer);
	}
	close(fd);
}
