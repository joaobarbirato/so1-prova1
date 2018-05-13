#pragma once
#include "main.h"

typedef struct{
    HackerQueue * hq;
    SerfQueue * sq;
    pthread_mutex_t * mutex;
    int n_hackers;   // number of hackers at the boat
    int n_serfs;
} Boat;