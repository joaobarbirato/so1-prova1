#include "../headers/main.h"
#include "../headers/boat.h"

struct pthread_board{
    Boat boat;
    int is_captain;
    int type;
};

int main(){
    int is_captain; // false
    Boat boat;
    boat.cap = 4;
    Queue q;
    pthread_t person;
    srand(time(NULL)); // random seed

    // a partir daqui, se repete
    is_captain = 0;
    boat.n_hackers = 0;
    boat.n_serfs = 0;
    pthread_barrier_init(&(boat.barrier), NULL, 4);
    pthread_mutex_init(&(boat.mutex), NULL);
    pthread_mutex_lock(&(boat.mutex));

    // Argumento para pthread_create
    struct pthread_board args;
    args.boat = boat;
    args.is_captain = is_captain;
    while(1){
        int person_type = random() % 2;
        args.type = person_type;
        pthread_create(&person,NULL, board,(void *)&args);
    }

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