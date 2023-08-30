#include <stdio.h>
#include "lifo.h"

int main() {
    stack s;stack_status status;
    element_type buffer[20];
    status= stack_init(s,buffer,20);
    if(status != stack_no_error){
        printf("=========error while initializing stack=========\n");
    }
    int i;
    for(i=0;i<20;i++){
        status =stack_push(s,i);
        if(status != stack_no_error){
            printf("error while pushing is %d\n",status);
            return 1;
        }
    }
    printf("=========pushed elements to the stack=========\n");
    status = stack_full(s);
    if(status != stack_is_full){
        printf("=========stack isn't full=========\n");
    }
    else{
        printf("=========stack is full=========\n");
    }
    for(i=0;i<20;i++){
        status =stack_pop(s);
        if(status != stack_no_error){
            printf("error while popping is %d\n",status);
            return 1;
        }
    }
    status = stack_empty(s);
    if(status != stack_is_empty){
        printf("=========stack isn't empty=========\n");
    }
    else{
        printf("=========stack is empty=========\n");
    }
    return 0;
}
