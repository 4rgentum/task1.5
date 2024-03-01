#ifndef FUNCS_H
#define FUNCS_H

#include "log.h"

void swap (log*, log*);
void shaker_sort (log*, int, int(*compare)(const void*, const void*));
void sift_down(log*, int, int, int(*compare)(const void*, const void*));
void heap_sort (log*, int, int(*compare)(const void*, const void*));

#endif
