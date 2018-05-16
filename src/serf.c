// TODO:
/*

the serf code is symmetric (except, of course, that it is 1000 times bigger,
full of bugs, and it contains an embedded web browser):

*/
#include "../headers/serf.h"

int manageSerfsBoat(Boat * b, int * is_captain){
    pthread_mutex_lock(b->mutex);
    b->n_serf++;
    if(b->n_serf == 4){
        sem_init(b->sq->sem, 0, 4);
        b->n_serf = 0;
        *is_captain = 1;
    }else if ((b->n_hackers && b->n_serfs) == 2){
        sem_init(b->hq->sem, 0, 2);
        sem_init(b->sq->sem, 0, 2);
        b->n_hackers = 0;
        b->n_serfs -= 2;
        *is_captain = 1;
    }else
        pthread_mutex_unlock(b->mutex);
    
    sem_wait(b->sq->sem);
