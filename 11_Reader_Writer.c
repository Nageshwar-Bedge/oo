//Writer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{
    key_t key = ftok("a.txt", 'A');
    int shmid = shmget(key, 1024, 0777 | IPC_CREAT);
    char *str = (char *)shmat(shmid, (void *)0, 0);

    printf("write data into file: ");
    fgets(str, 1024, stdin);

    printf("Data written in memory: %s\n", str);
    shmdt(str);
    system("ipcs -m");
    return 0;
}

//Reader
#include<sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	key_t key=ftok("a.txt",'A');
	int shmid= shmget( key ,1024,0777|IPC_CREAT);
	char *str= (char*) shmat(shmid,(void*)0,0);
	
	printf("Data read from memory: %s\n",str);
	shmdt(str);
	system("ipcs -m");
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
