// detachTest.c
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// Thread Function
void *t_function(void * data){
	// This thread uses much memory
	char a[100000];
	int num = *((int *) data);
	printf("Thread starts. Thread data=%d\n", num);
	sleep(5);
	printf("Thread finishes\n");
}
int main(){
	pthread_t p_thread;
	int thr_id;
	int status;
	int a = 100;
	printf("Creating Thread\n");
	thr_id = pthread_create(&p_thread, NULL, t_function, (void *)&a);
	if (thr_id < 0){
		perror("Error creating thread : ");
		exit(1);
	}
	// Allow the thread to run independently. This lets the thread 
	// release its memory when it finishes
	pthread_detach(p_thread);
	printf("Pausing\n");
	pause();
	return 0;
}
