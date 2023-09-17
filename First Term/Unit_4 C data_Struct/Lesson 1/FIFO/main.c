#include <stdio.h>
#include "fifo.h"

int main() {
    element_type buffer[10];
    queue q;
    queue_status status;
    status = queue_init(q,buffer,10);
    if (status != queue_no_error) {
        printf("Error initializing queue. Status: %d\n", status);
    }
    int i;
    for (i = 0; i < 10; i++) {
        status = queue_push(q, i);
        if (status != queue_no_error) {
            printf("Error Enqueueing item into FIFO. Status: %d\n", status);
        }
    }
    printf("=============Push is Done Successfully============\n");
    status = queue_full(q);
    if(status == queue_is_full){
        printf("=============queue is full=============\n");
    }
    for (i = 0; i < 10; i++) {
        status = queue_pop(q);
        if (status != queue_no_error) {
            printf("Error while popping: %d\n", status);
        }
    }
    status = queue_empty(q);
    if(status == queue_is_empty){
        printf("=============queue is empty=============\n");
    }
    return 0;
}
