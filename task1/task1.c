#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed for child 1");
        exit(EXIT_FAILURE);
    }
    if (pid1 == 0) {
        printf("Child 1: PID=%d, Parent PID=%d\n", getpid(), getppid());
        for (int i = 1; i <= 5; ++i) {
            printf("Child 1: %d\n", i);
            fflush(stdout);
            sleep(1);
        }
        exit(EXIT_SUCCESS);
    }

    pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed for child 2");
        exit(EXIT_FAILURE);
    }
    if (pid2 == 0) {
        printf("Child 2: PID=%d, Parent PID=%d\n", getpid(), getppid());
        for (char c = 'A'; c <= 'E'; ++c) {
            printf("Child 2: %c\n", c);
            fflush(stdout);
            sleep(1);
        }
        exit(EXIT_SUCCESS);
    }

    printf("Parent: created child1 PID=%d and child2 PID=%d. Parent PID=%d\n",
           (int)pid1, (int)pid2, (int)getpid());

    int status;
    pid_t wpid;
    int finished = 0;

    while (finished < 2) {
        wpid = wait(&status);
        if (wpid == -1) {
            perror("wait");
            break;
        } else {
            if (WIFEXITED(status)) {
                printf("Parent: child with PID=%d exited with status=%d\n",
                       (int)wpid, WEXITSTATUS(status));
            } else {
                printf("Parent: child with PID=%d terminated abnormally\n",
                       (int)wpid);
            }
        }
        finished++;
    }

    printf("Both children finished. Parent done.\n");
    return 0;
}
