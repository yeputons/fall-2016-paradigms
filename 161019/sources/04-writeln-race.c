#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void writeln(const char* s) {
    for (int i = 0; s[i]; i++) {
        putc(s[i], stdout);
    }
    putc('\n', stdout);
}

void* worker(void* arg __attribute__((unused))) {
    for (;;) {
        writeln("Hello from the second thread");
    }
}

int main(void) {
    pthread_t id;
    assert(pthread_create(&id, NULL, worker, NULL) == 0);
    for (;;) {
        writeln("Hello from the main thread");
    }
}
