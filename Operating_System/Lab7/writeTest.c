//writeTest.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#define MAX 1024	

int main(){
	int fd;
	int readNum=0;
	int writeNum=0;
	char buf[MAX];
	char *buf2 = "Success Writing!\n";
	int i;
	
	fd=open("writeTest.txt",O_RDWR);
	if (fd==-1){
		printf("file open failed!\n");
		perror("writeTest.txt");
		return 1;
	}
	writeNum = write(fd,buf2,strlen(buf2));
	memset(buf, 0x00, MAX);
	readNum = read(fd,buf,MAX-1);
	printf("readNum= : %d\n", readNum);
	printf("%s\n", buf);
	close(fd);
}

