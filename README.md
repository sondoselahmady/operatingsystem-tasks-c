# Operating Systems Tasks (C / POSIX)

Five C lab tasks written for a first-year Operating Systems course on Linux, covering processes, shared memory, threads, semaphore synchronization, and file I/O.

## Tasks
- `task1.c` — Forks two child processes (`fork`), prints PIDs/PPIDs, and waits for both with `wait`.
- `task2writer.c` & `task2reader.c` — Writes three integers to shared memory (`shmget` / `shmat`) and reads them back to compute sum, average, and cleanup (`shmctl`).
- `task3.c` — Creates three threads (`pthread_create`) and waits for completion (`pthread_join`).
- `task4.c` — Synchronizes counter updates across two threads using a binary semaphore (`sem_t`).
- `task5.c` — Writes five temperatures to `temps.txt`, reads them back, and prints the highest and lowest values.

## Build & Run (Linux / GCC)
```bash
gcc task1/task1.c -o task1 && ./task1
gcc task2/task2writer.c -o write && gcc task2/task2reader.c -o read
gcc task3/task3.c -pthread -o task3 && ./task3
gcc task4/task4.c -pthread -o task4 && ./task4
gcc task5/task5.c -o task5 && ./task5
