#include "lifo.h"
#include "stdint.h"
stack_status stack_init(stack s,element_type* buf,int length){
    s.bottom =s.top= buf;
    s.length=length;
    return stack_no_error;
}

stack_status stack_push(stack s,element_type num){
    if(s.count == s.length){
        return stack_is_full;
    }
    *s.top=num;
    s.count++;
    return stack_no_error;
}
stack_status stack_pop(stack s){
    if(s.count==0)
        return stack_is_empty;
    s.count--;
    s.top--;
    return stack_no_error;
}
stack_status stack_full(stack s){
    if(s.count == s.length){
        return stack_is_full;
    }
    return stack_null;
}
stack_status stack_empty(stack s){
    if(s.count==0)
        return stack_is_empty;
    return stack_null;
}



