#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    // Generate a unique key for shared memory
    key_t key = ftok("shmfile", 65);

    // Create shared memory segment of size 1024 bytes
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Attach shared memory to process
    int *arr = (int*) shmat(shmid, (void*)0, 0);

    // Prompt user for 3 integers
    printf("Enter 3 integers: ");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Data written to shared memory.\n");

    // Detach shared memory
    shmdt(arr);

    return 0;
}
