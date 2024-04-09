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
}
