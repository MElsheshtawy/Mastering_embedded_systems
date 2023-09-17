#ifndef LIFO_LIFO_H
#define LIFO_LIFO_H
#include "stdint.h"

#define element_type uint32_t

typedef struct{
    element_type length;
    element_type count;
    element_type*top;
    element_type*bottom;
}stack;

typedef enum{
    stack_is_full,
    stack_is_empty,
    stack_no_error,
    stack_null
}stack_status;

stack_status stack_init(stack s,element_type* buf,int length);
stack_status stack_push(stack s,element_type num);
stack_status stack_pop(stack s);
stack_status stack_full(stack s);
stack_status stack_empty(stack s);

#endif //LIFO_LIFO_H
