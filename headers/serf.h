#pragma once
#include "main.h"

typedef struct{
    Queue queue;
    sem_t * sem;
} SerfQueue;