# River-crossing Problem

### Executar:
```
$ make
```

### TO DO:

Após todas as inicializações (linha 18+ de `main.c`):

* Faco tds as treads
* Ponho elas nas filas adequadas
* Manda executar o board
* As 4 primeiras q entrarem invoca o barrier_destroy
* barco começa a andar (row)
* * a ultima thread da mutex_unlock
* * is_captain = 1
* * ativar a barreira dnv (barrier_init)

* pra cada thread:
* * pthread_create(&p, funçao);
* * delay(123u45189023758973143)
* * pthread_destroy
    
* qd as 4 morrerem:
* * barrier_destroy

o barco volta e repete o processo