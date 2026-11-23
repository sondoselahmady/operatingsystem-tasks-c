#include <stdio.h>
#include <pthread.h>
#include <assert.h>
void *worker(void *arg) {
    int thread_id = *((int *)arg);
    for (int i = 0; i < 3; i++) {
        printf("Thread %d is working\n", thread_id);	}
    return NULL;
}
int main() {
    pthread_t threads[3];
    int thread_ids[3] = {1, 2, 3};
    int rc;
    printf("Main begins\n");
for (int i = 0; i < 3; i++) {
        rc = pthread_create(&threads[i], NULL, worker, &thread_ids[i]);
        assert(rc == 0);	}
    for (int i = 0; i < 3; i++) {
        rc = pthread_join(threads[i], NULL);
        assert(rc == 0);	}
    printf("All threads completed.\n");
    printf("Main ends\n");
    return 0;
}
