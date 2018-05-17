#include "../headers/main.h"
#include "../headers/boat.h"

// testando fork

int main(){
    srand(time(NULL)); // random seed
    int is_captain; // false
    Boat boat;
    boat.cap = 4;
    Queue q;

    // a partir daqui, se repete
    is_captain = 0;
    boat.n_hackers = 0;
    boat.n_serfs = 0;
    pthread_barrier_init(&(boat.barrier), NULL, 4);
    pthread_mutex_init(&(boat.mutex), NULL);
    pthread_mutex_lock(&(boat.mutex));






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
