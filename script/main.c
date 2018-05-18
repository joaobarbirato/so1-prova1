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

void apresentacaoInicial(){
    printf("Bem-vindos ao primeiro projeto da disciplina Sistemas Operacionais 1!\n\n");
    printf("Esse projeto baseia-se no problema River crossing problem.\n");
    printf("Basicamente, este problema impoe uma regra de funcionamento: nao deve-se permitir um hacker e tres serf ou tres hackers e um serf no mesmo barco.\n\n");
    printf("Dado a largada, apenas sera apresentado permutacoes que respeite as regras impostas! \n");
    sleep(10);
    system("clear");
}
void apresentacao(){
    printf(" Vamos la                                                                    \n");
    printf(" _ _ _                                                                       \n");
    printf(" _|   |                                                                      \n");
    printf(" _|_ _|                                                                      \n");
    printf("      |                                                                      \n");
    printf("   _ _|_ _ _ _ _ _ __                                                        \n");
    printf("  |_             _ __|                                                       \n");
    printf("    |_ _ _ _ _ _|/                                                           \n");
}

void apresentacao1(){
    printf(" Vamos la                                                                    \n");
    printf("               _ _ _                                                         \n");
    printf("               _|   |                                                        \n");
    printf("               _|_ _|                                                        \n");
    printf("                |                                                            \n");
    printf("             _ _|_ _ _ _ _ _ __                                              \n");
    printf("            |_             _ __|                                             \n");
    printf("              |_ _ _ _ _ _|/                                                 \n");
}  

void apresentacao2(){
    printf(" Vamos la                                                                    \n");
    printf("                                  _ _ _                                     \n");
    printf("                                  _|   |                                    \n");
    printf("                                  _|_ _|                                    \n");
    printf("                                   |                                        \n");
    printf("                                _ _|_ _ _ _ _ _ __                          \n");
    printf("                               |_             _ __|                         \n");
    printf("                                |_ _ _ _ _ _|/                               \n");
}

void apresentacao3(){
    printf(" Vamos la                                                                    \n");
    printf("                                                     _ _ _                   \n");
    printf("                                                     _|   |                  \n");
    printf("                                                     _|_ _|                  \n");
    printf("                                                      |                      \n");
    printf("                                                   _ _|_ _ _ _ _ _ __        \n");
    printf("                                                  |_             _ __|       \n");
    printf("                                                    |_ _ _ _ _ _|/           \n");
}

void apresentacao4(){
    printf("Entao, eh dada a largada!!\n");
    printf("Presentes no barco:\n\n");
}

// main
int main(){
    system("clear");
    apresentacaoInicial();
    for (int p = 0; p < 2; p++)
    {
        apresentacao();
        sleep(1);
        system("clear");
        apresentacao1();
        sleep(1);
        system("clear");
        apresentacao2();
        sleep(1);
        system("clear");
        apresentacao3();
        sleep(1);
        system("clear");
    }
    apresentacao4();
    sleep(5);



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
