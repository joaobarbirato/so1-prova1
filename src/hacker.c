//implementa o coiso do livro

// TODO: 
/*

mutex.wait()
    hackers += 1
    if hackers == 4:
        hackerQuee.signal(4)
        hackers = 0
        isCaptain = True
    elif hackers == 2 and serfs >= 2:
        hackerQueue.signal(2)
        serfQueue.signal(2)
        serfs -= 2
        hackers = 0
        isCaptain = True
    else:
        mutex.signal()                  # captain keeps the mutex

hackerQueue.wait()

board() //subir no barco
barrier.wait()

if isCaptain: //capitao, pega o mutex e mexe o barco
    rowBoat()
    mutex.signal()                      # captain releases the mutex

*/
#include "../headers/main.h"
#include "../headers/boat.h"

int manageHackersBoat(Boat * b, int * is_captain){
    pthread_mutex_lock(b->mutex);
    b->n_hackers++;
    if(b->n_hackers == 4){
        sem_init(b->hq->sem, 0, 4);
        b->n_hackers = 0;
        *is_captain = 1;
    }else if ((b->n_hackers && b->n_serfs) == 2){
        sem_init(b->hq->sem, 0, 2);
        sem_init(b->sq->sem, 0, 2);
        b->n_hackers = 0;
        b->n_serfs -= 2;
        *is_captain = 1;
    }else
        pthread_mutex_unlock(b->mutex);
    
    sem_wait(b->hq->sem);

/*
    //TODO:
    board()
    barrier.wait()

    if isCaptain:
        rowBoat()
        mutex.signal()                      # captain releases the mutex
*/

    return 0; //?
};
