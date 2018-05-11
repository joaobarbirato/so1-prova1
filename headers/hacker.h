#include "../headers/queue.h"

typedef struct{
    Queue queue;
    pthread_mutex_t * mutex;
}  HackerQueue;