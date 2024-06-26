// createTest.c
#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

// Thread Function
// Both threads will perform this loop infinitely, with different data

void *t_function(void * data){
	int id;
	int i=0;
	id = *((int *) data);
	while(1) // Loop infinitely
		{
		printf("Thread Number %d : i = %d\n", id, i);
		i++;
		sleep(1);
	}
}

int main(){
	pthread_t p_thread[2];
	int thr_id; int status;
	int a = 1;
	int b = 2;
	// Create two threads
	thr_id = pthread_create(&p_thread[0], NULL, t_function, (void *)&a);
	if (thr_id < 0){
		perror("Error creating thread : "); 
		exit(1);
	}
	thr_id = pthread_create(&p_thread[1], NULL, t_function, (void *)&b);
	if (thr_id < 0){
		perror("Error creating thread: "); 
		exit(1);
	}
		
	// Wait until the two threads finish
	pthread_join(p_thread[0], (void **)&status);
	pthread_join(p_thread[1], (void **)&status);
	return 0;
}
