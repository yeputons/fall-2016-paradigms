#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 500000000
#define M 10000

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
        int data_snapshot = data;
        if (data_snapshot % 2 == 0) {
            printf("data is %d (in progress)\n", data_snapshot);
            assert(data_snapshot % 2 == 0);
        }
    }
    assert(pthread_join(id, NULL) == 0);
    printf("data is %d\n", data);
    return 0;
}
