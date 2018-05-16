#pragma once
#include "main.h"

typedef struct{
    HackerQueue * hq; //fila de hackers
    SerfQueue * sq; //fila de funcionarios
    pthread_mutex_t * mutex; 
    int n_hackers;   // number of hackers at the boat
    int n_serfs;
} Boat;
