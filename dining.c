#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5  // Number of philosophers (and forks)
int i;
sem_t forks[N];
sem_t table;

void *philosopher(void *arg) {
    int id = *(int *)arg;
    int left_fork = id;
    int right_fork = (id + 1) % N;

    while (1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(rand() % 3 + 1); // Philosophers think for some time

        sem_wait(&table); // Acquire access to the table
        sem_wait(&forks[left_fork]); // Acquire left fork
        sem_wait(&forks[right_fork]); // Acquire right fork

        printf("Philosopher %d is eating.\n", id);
        sleep(rand() % 3 + 1); // Philosophers eat for some time

        sem_post(&forks[right_fork]); // Release right fork
        sem_post(&forks[left_fork]); // Release left fork
        sem_post(&table); // Release access to the table
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    pthread_t philosophers[N];
    int ids[N];

    sem_init(&table, 0, N - 1);

    for (i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);

    for (i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (i = 0; i < N; i++)
        pt hread_join(philosophers[i], NULL);

    for ( i = 0; i < N; i++)
        sem_destroy(&forks[i]);

    sem_destroy(&table);

    return 0;
}

