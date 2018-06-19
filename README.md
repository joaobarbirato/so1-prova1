# River-crossing Problem

## Contexto
Somewhere near Redmond, Washington there is a rowboat that is used by both Linux hackers and Microsoft employees (serfs) to cross a river. The ferry can hold exactly four people; it won’t leave the shore with more or fewer. Toguarantee the safety of the passengers, it is not permissible to put one hacker in the boat with three serfs, or to put one serf with three hackers. Any other
combination is safe.
As each thread boards the boat it should invoke a function calledboard. You must guarantee that all four threads from each boatload invoke board before any of the threads from the next boatload do.
After all four threads have invoked board, exactly one of them should call a function named rowBoat, indicating that that thread will take the oars. It doesn’t matter which thread calls the function, as long as one does.
Don’t worry about the direction of travel. Assume we are only interested in traffic going in one of the directions.
(http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf) [Little Book of Semaphores, pag 148]

## Elementos
### 2 Semáforos
* Hacker's queue; (headers/boat.h)
* Serf's queue; (headers/boat.h)

### 1 Mutex
* Mutex; (headers/boat.h)

### 1 Barreira
* Barrier; (headers/boat.h)

### Threads
* Threads criadas indeterminadamente; (script/main.c)
  * Cada Thread chama a função `board`.

## Executar:
```
$ make
```
