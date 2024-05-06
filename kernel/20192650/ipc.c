<<<<<<< HEAD
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int count;
void *runner(void *param);

int ipc(int argc, char *argv[])
{
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    pthread_join(tid, NULL);
    printf("count = %d \n", count);
}

void *runner(void *param)
{
    int i, upper = atoi(param);
    count = 0;
    for (i = 1; i < upper; i++)
    {
        count += 1;
    }
    pthread_exit(0);
=======
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int ipc(void)
{
    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE];

    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1)
    {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    if (pid > 0)
    { //Parent
        close(fd[READ_END]);
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        close(fd[WRITE_END]);
    }
    else
    { //Child
        close(fd[WRITE_END]);
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("read %s", read_msg);
        close(fd[READ_END]);
    }

    return 0;
>>>>>>> 3c963fd68c47e345ce0b69d548ccbc6229b64c6d
}
