#pragma once

typedef struct{
    int * queue;
    int size;
} Queue;

int insert_queue(Queue*, const int);
int remove_queue(Queue*, const int);