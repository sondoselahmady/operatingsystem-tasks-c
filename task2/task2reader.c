#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    key_t key = ftok("shmfile", 65);     // Use the same key as writer
    int shmid = shmget(key, 1024, 0666);  // Access the shared memory segment
    int *arr = (int*) shmat(shmid, (void*)0, 0); // Attach shared memory

    // Read and display integers
    printf("Data read from shared memory:\n");
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        printf("%d ", arr[i]);
        sum += arr[i];
    }
    printf("\n");

    // Calculate sum and average
    float avg = sum / 3.0;
    printf("Sum = %d, Average = %.2f\n", sum, avg);

    // Detach shared memory
    shmdt(arr);

    // Remove shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
