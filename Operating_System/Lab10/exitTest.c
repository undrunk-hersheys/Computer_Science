// exitTest.c
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *t_function(void * data){
	long int num= *((long int *)data);
	printf("Thread received parameter num=%ld\n", num);
	num +=10;
	printf("Thread increased num to %ld\n", num);
	sleep(1);
	pthread_exit((void *) num);
}

int main(){
	pthread_t p_thread;
	int thr_id;
	long int status;
	long int a = 100;
	thr_id = pthread_create(&p_thread, NULL, t_function, (void *)&a);
	if (thr_id < 0)	{
	perror ("Error creating thread : ");
	exit(1);
	}
	pthread_join(p_thread, (void **)&status);
	printf("Thread joined. Thread returned status=%ld\n", status);
	return 0;
}
