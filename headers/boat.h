#pragma once
#include "main.h"

// Boat definition
typedef struct{
    pthread_mutex_t mutex;      // mutex
    pthread_barrier_t barrier;  // barrier
    int n_hackers;   // number of hackers at the boat
    int n_serfs;     // number of serfs at the boat
    int cap;         // person's cap
    sem_t hackers_queue;    // not used, why?
    sem_t serfs_queue;      // not used, why?
} Boat;

// prototypes
void * board(void *a);
void row_boat(sem_t * sem_queue, int * is_captain);
void print_boat_fleet(const Boat boat);