// argument_sender.c
#include <stdio.h>
#include <unistd.h>

int main() 
{
    char *program_path = (char*)"./e2";
    char *args[] = {program_path, (char*)"42", (char*)"55", (char*)"13", NULL};

    printf("Executing %s with arguments:\n", program_path);

    for (int i = 1; args[i] != NULL; i++) 
	{
        printf("%s ", args[i]);
    }
    printf("\n");

    execv(program_path, args);

    perror("execv");
    return 1;
}