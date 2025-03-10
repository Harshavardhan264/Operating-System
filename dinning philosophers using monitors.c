#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5  
#define LEFT (i + N - 1) % N  
#define RIGHT (i + 1) % N  

enum { THINKING, HUNGRY, EATING } state[N];
pthread_mutex_t mutex;
pthread_cond_t cond_vars[N];

void test(int i) {
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING;
        pthread_cond_signal(&cond_vars[i]);
    }
}

void take_forks(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = HUNGRY;
    test(i);
    while (state[i] != EATING) {
        pthread_cond_wait(&cond_vars[i], &mutex);
    }
    pthread_mutex_unlock(&mutex);
}

void put_forks(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = THINKING;
    test(LEFT);
    test(RIGHT);
    pthread_mutex_unlock(&mutex);
}

void* philosopher(void* num) {
    int i = *(int*)num;
    while (1) {
        // Thinking
        sleep(1);
        // Hungry
        take_forks(i);
        // Eating
        sleep(1);
        // Put down forks
        put_forks(i);
    }
}

int main() {
    pthread_t threads[N];
    int indices[N];

    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < N; i++) {
        pthread_cond_init(&cond_vars[i], NULL);
        indices[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &indices[i]);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    for (int i = 0; i < N; i++) {
        pthread_cond_destroy(&cond_vars[i]);
    }
    return 0;
}
