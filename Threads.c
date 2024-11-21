#include <stdio.h>
#include <pthread.h>

int saldo;

void * printHola(void* arg) {
    int pid = *((int *)arg);
    printf("Hola! Soy el hilo %d\n", pid);
    pthreadExit(NULL);

    return NULL;
}

void *incrementaSaldo(void *arg) {
    saldo += 100;
}

int main() {
    int NUMTHREADS = 20;
    pthreadT threadStatus[NUMTHREADS];
    int pids[20];

    saldo = 0;

    for (int i = 0; i < NUMTHREADS; i++) {
        pids[i] = i;
        pthreadCreate(&threadStatus[i], NULL, printHola, (void *)&pids[i]);
        pthreadCreate(&threadStatus[i], NULL, incrementaSaldo, NULL);
    }

    for (int i = 0; i < NUMTHREADS; i++) {
        pthreadJoin(threadStatus[i], NULL);
    }

    printf("Saldo final: %d\n", saldo);
    pthreadExit(NULL);
}