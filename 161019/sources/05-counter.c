#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 500000000
#define M 1000

int data;
void* worker(void* arg __attribute__((unused))) {
    for (int i = 0; i < N; i++) {
        data++;
    }
    return NULL;
}

int main(void) {
    pthread_t id;
    assert(pthread_create(&id, NULL, worker, NULL) == 0);
    for (int i = 0; i < M; i++) {
        printf("data is %d (in progress)\n", data);
    }
    assert(pthread_join(id, NULL) == 0);
    printf("data is %d\n", data);
    return 0;
}
