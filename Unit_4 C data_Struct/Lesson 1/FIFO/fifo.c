#include "fifo.h"
#include "stdio.h"
queue_status queue_init(queue q,element_type* buf,int length){
    if(!buf)
        return queue_null;
    q.bottom=q.top=q.index=buf;
    q.length=length;
    q.count=0;
    return queue_no_error;
}
queue_status queue_push(queue q, int num){
    if(q.count == q.length)
        return queue_is_full;
    q.count++;
    if(q.top == q.bottom+q.length+1){
        q.top=q.bottom;
        *q.top = num;
    }
    else{
        q.top++;
        *q.top=num;
    }
    return  queue_no_error;
}
queue_status queue_pop(queue q){
    if(!q.count)
        return queue_is_empty;
    q.count--;
    if(q.index == q.top){
        q.index=q.top=q.bottom;
    }
    else{
        q.index++;
    }
    return queue_no_error;
}
queue_status queue_full(queue q){
    if(q.count == q.length)
        return queue_is_full;
}
queue_status queue_empty(queue q){
    if(!q.count)
        return queue_is_empty;
}
