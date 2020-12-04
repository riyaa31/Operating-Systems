//RIYA SHAH, 201817129
//CS 2004, ASSIGNMENT 5
//QUESTION 3

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int shared=1;	//shared variable
sem_t s;	//semaphore variable

void *fun1(){
	sem_wait(&s);	
	int local = shared+1;
	sleep(1);
	shared = local;
	sem_post(&s);
}
void *fun2(){
	sem_wait(&s);
	int local = shared -1;
	sleep(1);
	shared = local;
	sem_post(&s);
}
int main(){
	sem_init(&s,0,1); //initialize sem varibale, 2nd arg is no of process sharing, 3rd arg is semaphore value
	pthread_t one,two;
	pthread_create(&one,0,fun1,NULL);
	pthread_create(&two,0,fun2,NULL);
	pthread_join(one,NULL);
	pthread_join(two,NULL);
	
	return printf("Thread Joined. Shared Var Val : %d\n",shared);
}