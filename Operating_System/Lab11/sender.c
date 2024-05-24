// sender.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define FIFO_FILE "/tmp/fifo1"
int main(void)
{
	int fd;
	char * str = "Message from Sender";
	if (-1 == (fd = open(FIFO_FILE, O_WRONLY)))
	{
		perror("Error opening FIFO");
		exit(1);
	}
	write(fd, str, strlen(str));
	close(fd);
}
