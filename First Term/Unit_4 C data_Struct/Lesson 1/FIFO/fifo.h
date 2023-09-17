// Eng.Elsheshtawy
#ifndef FIFO_FIFO_H
#define FIFO_FIFO_H
#include "stdio.h"
#include "stdint.h"

#define element_type uint32_t
#define width 10


typedef struct{
    int length;
    int count;
    element_type* top;
    element_type* bottom;
    element_type* index;
}queue;

typedef enum{
    queue_no_error,
    queue_is_full,
    queue_is_empty,
    queue_null
}queue_status;

queue_status queue_init(queue q,element_type* buf,int length);
queue_status queue_push(queue q, int num);
queue_status queue_pop(queue q);
queue_status queue_full(queue q);
queue_status queue_empty(queue q);

#endif //FIFO_FIFO_H
