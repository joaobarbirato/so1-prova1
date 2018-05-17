#include "../headers/boat.h"

// pthread_create function params
struct pthread_board{
    Boat * boat;
    int is_captain;
    int type;
};

// Board function
// The caller thread asks permition to use boat's resources by signaling the pthread_barrier
// There can never be 1 serf with 3 hackers or 3 hackers with 1 serf
void * board(void *a){
    struct pthread_board * args = (struct pthread_board *)a;
        
    if(args->type == SERF){

        // it's a serf!
        if(!args->is_captain){      // the boat is still at the shore
            args->boat->n_serfs++;
            // The last thread (person) enters here:
            if(args->boat->n_serfs == args->boat->cap){
                print_boat_fleet(*args->boat);
                pthread_barrier_wait(&(args->boat->barrier));    // It signals the barrier

                args->is_captain = 1;   // it becomes the captain

                // and rows the boat
                row_boat(&args->boat->serfs_queue, &args->is_captain);

                // by the and of the travel, the boat is empty
                args->boat->n_serfs = 0;
            }else if (args->boat->n_hackers == args->boat->cap/2 && args->boat->n_serfs == args->boat->cap/2){
                print_boat_fleet(*args->boat);
                pthread_barrier_wait(&(args->boat->barrier));    // It signals the barrier
                args->is_captain = 1;   // it becomes the captain

                // and rows the boat
                row_boat(&args->boat->serfs_queue, &args->is_captain);

                // by the and of the travel, the boat is empty
                args->boat->n_hackers = 0;
                args->boat->n_serfs = 0;
            }else{
                if(args->boat->n_hackers + args->boat->n_serfs >= args->boat->cap){
                    // If the boat is still full
                    // we have to recalculate how many are at the boat
                    args->boat->n_serfs--;
                }else{
                    // If it's not the last thread, it enters here
                    print_boat_fleet(*args->boat);
                    pthread_barrier_wait(&(args->boat->barrier));    // It signals the barrier
                    pthread_mutex_unlock(&(args->boat->mutex));
                }
            }
        }
        sem_wait(&args->boat->hackers_queue);           // not used. why?
    }else{
        // it's a hacker!
        if(!args->is_captain){      // the boat is still at the shore
            args->boat->n_hackers++;
            if(args->boat->n_hackers == args->boat->cap){
                print_boat_fleet(*args->boat);

                pthread_barrier_wait(&(args->boat->barrier));    // It signals the barrier
                args->is_captain = 1;   // it becomes the captain

                // and rows the boat
                row_boat(&args->boat->hackers_queue, &args->is_captain);

                // by the and of the travel, the boat is empty
                args->boat->n_hackers = 0;
            }else if (args->boat->n_hackers == args->boat->cap/2 && args->boat->n_serfs == args->boat->cap/2){
                print_boat_fleet(*args->boat);

                pthread_barrier_wait(&(args->boat->barrier));    // It signals the barrier
                args->is_captain = 1;   // it becomes the captain

                // and rows the boat
                row_boat(&args->boat->hackers_queue, &args->is_captain);

                // by the and of the travel, the boat is empty
                args->boat->n_serfs = 0;
                args->boat->n_hackers = 0;
            }else{
                if(args->boat->n_hackers + args->boat->n_serfs >= args->boat->cap){
                    // If the boat is still full
                    // we have to recalculate how many are at the boat
                    args->boat->n_hackers--;
                }else{
                    // If it's not the last thread, it enters here
                    print_boat_fleet(*args->boat);
                    pthread_barrier_wait(&(args->boat->barrier));    // It signals the barrier
                    pthread_mutex_unlock(&(args->boat->mutex));
                }
            }
        }
        sem_wait(&args->boat->serfs_queue);             // not used. why?
    }
}; // end board

// Row function
// The last thread that signals the barrier activates boat's mutex
// and the boat sets sail
void row_boat(sem_t * sem_queue, int * is_captain){
    printf("Row!!\n");
    sleep(5);               // resource

    printf("Unload!!\n");   // unload console exhibition
    sleep(5);       // resource
    sem_post(sem_queue);                                // not used. why?
    *is_captain = 0;
};// end row

// Print boat function
void print_boat_fleet(const Boat boat){
    printf("h: %d, s: %d\n", boat.n_hackers, boat.n_serfs);
}//  end print boat