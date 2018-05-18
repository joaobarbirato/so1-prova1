/*
    Crossing River Problem
    Authors:
        Gabrieli Santos             RA: 726523
        Joao Gabriel Melo Barbirato RA: 726546
        Rodrigo Pesse de Abreu      RA: 726588

*/
#include "../headers/main.h"
#include "../headers/boat.h"
//#include <conio.h>

// pthread_create function params
struct pthread_board{
    Boat * boat;
    int is_captain;
    int type;
};

// main
int main(){
    srand(time(NULL)); // random seed

    int is_captain;
    Boat boat;
    Queue q;
    pthread_t person;
    is_captain = 0;

    // initialize boat with standard configuration
    boat.cap = 4;
    boat.n_hackers = 0;
    boat.n_serfs = 0;
    pthread_barrier_init(&(boat.barrier), NULL, 4);
    pthread_mutex_init(&(boat.mutex), NULL);
    pthread_mutex_lock(&(boat.mutex));

    sem_init(&boat.hackers_queue, 0, 0);    // not used, why?
    sem_init(&boat.serfs_queue, 0, 0);      // not used, why?

    struct pthread_board args;
    args.boat = &boat;
    args.is_captain = is_captain;
    int i;

    // Creating threads
    while(1){
        sleep(1);
        int person_type = random() % 2; // with random type (HACKER or SERF)
        args.type = person_type;
        pthread_create(&person,NULL, board,(void *)&args);

/*	int stop;
	do{
		if(kbhit()){
			stop = getch();
			if(stop == 1){
				printf("Encerrando programa...");
				break;
			}
		}
	}*/

    }
    pthread_join(person, NULL);

    return 0;
} // endmain
