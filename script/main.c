#include "../headers/main.h"
#include "../headers/boat.h"


int main(){
    srand(time(NULL)); // random seed

    Boat boat;

    boat.n_hackers = 0;
    boat.n_serfs = 0;

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