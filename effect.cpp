#include <malloc.h>

#include "effect.h"

EFFECT* createEffect(EFFECT::KIND kind, uint64_t stamp, uint64_t length, uint64_t step) {
    EFFECT* res = (EFFECT*)malloc(sizeof(EFFECT));
    res->kind = kind;
    res->_stamp = stamp;
    res->_prev = stamp;
    res->_length = length;
    res->_step = step;
    res->prev=0;
    res->next=0;
    return res;
}

void DeleteEffect(EFFECT* e)
{
    if (e->prev && e->next)
    {
        e->prev->next = e->next;
        e->next->prev = e->prev;
    }
    free(e);
}