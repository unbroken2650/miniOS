#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "system.h"
void print_minios(char *str);

int main()
{
    print_minios("[MiniOS SSU] Hello, World!");

    char *input;
    char *input_num;

    while (1)
    {
        // readline을 사용하여 입력 받기
        input = readline("커맨드를 입력하세요(종료:exit) : ");

        if (strcmp(input, "exit") == 0)
        {
            break;
        }

        if (strcmp(input, "minisystem") == 0)
        {
            minisystem();
        }

        if (strcmp(input, "function2") == 0)
        {
            function2();
        }
        if (strcmp(input, "fork start") == 0)
        {
            newFork();
        }
        if (strcmp(input, "ipc start") == 0)
        {
            input_num = readline("Type Number: ");
            char *ipc_argv[] = {"ipc", input_num, NULL};
            int ipc_argc = sizeof(ipc_argv) / sizeof(char *) - 1;
            if (input_num != NULL && input_num != "\n")
            {
                ipc(ipc_argc, ipc_argv);
            }
            else
            {
                printf("No valid number");
            }
        }
        else
            system(input);
    }

    // 메모리 해제
    free(input);
    print_minios("[MiniOS SSU] MiniOS Shutdown........");

    return (1);
}

void print_minios(char *str)
{
    printf("%s\n", str);
}
