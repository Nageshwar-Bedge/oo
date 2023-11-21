#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() 
{
    pid_t child_pid = fork();

    // Parent process
    if (child_pid > 0) 
	{
        printf("Parent process (PID %d) created with child PID: %d\n", getpid(), child_pid);
        sleep(5);
        printf("Parent process exiting (PID %d)\n", getpid());
	system("ps");
    }

    // Child process
    else 
	{
        printf("Child process (PID %d) exited\n", getpid());
        exit(0);
    }
    return 0;
}
