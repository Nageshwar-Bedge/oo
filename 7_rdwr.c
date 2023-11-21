#include<iostream>
#include<semaphore.h>
#include<pthread.h>
using namespace std;

sem_t w,r ;
int arc=0;
int rc=0;
int wc=0;

void*writer(void*arg)
{
	sem_wait(&w);
	wc++;
	cout<<"\n"<<"Writer is writing:"<<wc<<"\n";
	sem_post(&w);
}

void*reader(void*arg)
{
	sem_wait(&r);
	arc++;
	if(arc==1)
	{
		sem_wait(&w);
	}
	sem_post(&r);
	rc++;
	cout<<"\n"<<"Reader is reading:"<<rc<<"\n";
	sem_wait(&r);
	arc--;
	if(arc==0)
	{
		sem_post(&w);
	}
	sem_post(&r);
}

int main()
{
	sem_init(&r,0,1);
	sem_init(&w,0,1);
	
	pthread_t write[3],read[3];
	
	for(int i=0;i<3;i++)
	{
	 pthread_create(&write[i],NULL,writer,NULL);
	 pthread_create(&read[i],NULL,reader,NULL);
	}
	for(int i=0;i<3;i++)
	{
	 pthread_join(write[i],NULL);
	 pthread_join(read[i],NULL);
	}
	return 0;
}