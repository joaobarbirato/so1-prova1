#pragma once
#include "main.h"

typedef struct{
    pthread_mutex_t mutex; 
    pthread_barrier_t barrier;
    int n_hackers;   // number of hackers at the boat
    int n_serfs;
    int cap;
} Boat;

void * board(void *a);
