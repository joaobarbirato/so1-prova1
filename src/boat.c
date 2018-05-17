#include "../headers/boat.h"

struct pthread_board{
    Boat boat;
    int is_captain;
    int type;
};

void * board(void *a){
    struct pthread_board * args = (struct pthread_board *)a;
    if(args->type == SERF){
        args->boat.n_serfs++;
        if(args->boat.n_serfs == 4){
            pthread_barrier_wait(&(args->boat.barrier));
            args->boat.n_serfs = 0;
            args->is_captain = 1;
        }else if ((args->boat.n_hackers && args->boat.n_serfs) == 2){
            pthread_barrier_wait(&(args->boat.barrier));
            args->boat.n_hackers = 0;
            args->boat.n_serfs = 0;
            args->is_captain = 1;
        }else{
            pthread_barrier_wait(&(args->boat.barrier));
            pthread_mutex_unlock(&(args->boat.mutex));  //?
        }
    }else{
        args->boat.n_hackers++;
        if(args->boat.n_hackers == 4){
            pthread_barrier_wait(&(args->boat.barrier));
            args->boat.n_hackers = 0;
            args->is_captain = 1;
        }else if ((args->boat.n_hackers && args->boat.n_serfs) == 2){
            pthread_barrier_wait(&(args->boat.barrier));
            args->boat.n_hackers = 0;
            args->boat.n_serfs = 0;
            args->is_captain = 1;
        }else{
            pthread_mutex_unlock(&(args->boat.mutex));  //?
        }
    }
    if(args->type == HACKER)
        printf("HACKER em board!\n");
    if(args->type == SERF)
        printf("SERF em board!\n");
}