#include "../headers/main.h"

int main(){
    pthread_mutex_t * mutex;
    printf("Helo world!\n");
    return 0;
}
/*
barrier = Barrier(4)
mutex = Semaphore(1)
hackers = 0
serfs = 0
hackerQueue = Semaphore(0)
serfQueue = Semaphore(0)
local isCaptain = False
*/