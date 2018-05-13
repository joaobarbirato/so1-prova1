#include "../headers/queue.h"

// Insert
int insert_queue(Queue*q, const int x){
    int i;
    for(i = 0; i < q->size; i++){
        if(q->queue[i] == -1)
            q->queue[i] = x;
            return i;
    }
    return -1;
}; // end insert

// Remove
int remove_queue(Queue*q, const int pos){
    int r = q->queue[pos];
    q->queue[pos] = -1;
    return r;
} // end remove