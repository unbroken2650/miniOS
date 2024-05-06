#include <stdio.h>

#define NUM_PROCESSES 5
#define TIME_SLICE 3

// 프로세스를 표현하는 구조체
typedef struct
{
    int pid;
    int burstTime;
} Process;

void roundRobin(Process processes[], int numProcesses, int timeSlice)
{
    int time = 0;
    int processesLeft = numProcesses; // 남은 프로세스 수

    // 모든 프로세스의 실행 시간이 0이 될 때까지 반복
    while (processesLeft > 0)
    {
        for (int i = 0; i < numProcesses; i++)
        {
            if (processes[i].burstTime > 0)
            {
                printf("Time %d: Process %d is running\n", time, processes[i].pid);

                // 프로세스 실행
                if (processes[i].burstTime > timeSlice)
                {
                    processes[i].burstTime -= timeSlice;
                    time += timeSlice;
                }
                else
                {
                    time += processes[i].burstTime;
                    processes[i].burstTime = 0;
                    processesLeft--; // 프로세스 완료
                    printf("Time %d: Process %d has finished executing\n", time, processes[i].pid);
                }
            }
        }
    }
}

int roundrobin()
{
    Process processes[NUM_PROCESSES] = {
        {1, 10},
        {2, 22},
        {3, 8},
        {4, 1},
        {5, 6}};

    roundRobin(processes, NUM_PROCESSES, TIME_SLICE);
    return 0;
}
