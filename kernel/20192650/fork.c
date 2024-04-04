#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int newFork()
{
    pid_t pid;
    /* fork a child process */
    pid = fork(); // pid(p): pid of child process; pid(c): 0
    if (pid < 0)
    { /* error occured. Child starts here */
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0)
    {
        printf("20192650_Child Process!\n"); /* child process */
        printf("PID of Child Process : %d\n", getpid());
    }
    else
    { /* parent process */
        /* parent will wait for the child to complete */
        wait(NULL);
        printf("PID of Parent Process : %d\n", getpid());
        printf("Child process has terminated.\n");
    }
    return 0;
}
