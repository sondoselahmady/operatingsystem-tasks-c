#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int counter = 0;      // Shared counter
sem_t semaphore;      // Binary semaphore

void* update_counter(void* arg) {
    long id = (long)arg;
    for (int i = 0; i < 5; i++) {
        sem_wait(&semaphore); // Acquire semaphore (enter critical section)
        printf("Thread %ld is updating the counter\n", id);
        counter++;            // Critical section
        sleep(1);             // Simulate some work
        sem_post(&semaphore); // Release semaphore
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    sem_init(&semaphore, 0, 1); // Initialize binary semaphore with value = 1

    // Create threads
    pthread_create(&t1, NULL, update_counter, (void*)1);
    pthread_create(&t2, NULL, update_counter, (void*)2);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&semaphore); // Destroy semaphore
    printf("Final Counter Value: %d\n", counter); // Final counter value
    return 0;
}
