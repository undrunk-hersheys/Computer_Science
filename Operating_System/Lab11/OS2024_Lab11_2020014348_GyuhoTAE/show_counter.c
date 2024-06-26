//show_counter.c
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define KEY_NUM 9527
#define MEM_SIZE 1024
int main(void){
	int shm_id;
	void *shm_addr;
	if (-1==(shm_id = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT | 0666))){
		printf("failed to create shared memory\n");
		return -1;
	}
	if ((void *)-1 == (shm_addr = shmat (shm_id, (void *)0, 0))){
		printf("failed to access shared memory \n");
		return -1;
	}
	while(1){
		printf("%s\n", (char *)shm_addr);
		sleep(1);
	}
	return 0;
}
