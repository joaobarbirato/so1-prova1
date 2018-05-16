#include "../headers/boat.h"

void board(Boat * b, int * is_captain, const int type){
    if(type == SERF){
        b->n_serfs++;
        if(b->n_serfs == 4){
            pthread_barrier_wait(&(b->barrier));
            b->n_serfs = 0;
            *is_captain = 1;
        }else if ((b->n_hackers && b->n_serfs) == 2){
            pthread_barrier_wait(&(b->barrier));
            b->n_hackers = 0;
            b->n_serfs = 0;
            *is_captain = 1;
        }else{
            pthread_barrier_wait(&(b->barrier));
            pthread_mutex_unlock(&(b->mutex));  //?
        }
    }else{
        b->n_hackers++;
        if(b->n_hackers == 4){
            pthread_barrier_wait(&(b->barrier));
            b->n_hackers = 0;
            *is_captain = 1;
        }else if ((b->n_hackers && b->n_serfs) == 2){
            pthread_barrier_wait(&(b->barrier));
            b->n_hackers = 0;
            b->n_serfs = 0;
            *is_captain = 1;
        }else{
            pthread_mutex_unlock(&(b->mutex));  //?
        }
    }
}