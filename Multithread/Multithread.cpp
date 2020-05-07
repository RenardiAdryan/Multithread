#include "stdio.h"
#include <pthread.h>
#include <unistd.h>

int x[5];
void *increment1(void *arg){
	static int count;
	while(1){
	count++;

	if(count>15000){
	x[0]++;count=0;}
	if(x[0]>10000){x[0]=0;}
    }
}

void *increment2(void *arg){
	static int count;
	while(1){
	count++;

	if(count>50000){
	x[1]++;count=0;}
	if(x[1]>10000){x[1]=0;}
	}
}

int main(int argc, char *argv[]){

	pthread_t t1,t2;
    pthread_create(&t1,NULL,increment1,NULL);
	pthread_create(&t2,NULL,increment2,NULL);
	while(1){
		printf("Data X[0]=%d || Data X[1]=%d \n",x[0],x[1]); 
		usleep(50*1000);
	}

}