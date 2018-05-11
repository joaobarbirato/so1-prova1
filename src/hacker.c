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

board()
barrier.wait()

if isCaptain:
    rowBoat()
    mutex.signal()                      # captain releases the mutex

*/
#include "../headers/hacker.h"