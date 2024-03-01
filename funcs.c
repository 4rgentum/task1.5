#include <stdio.h>
#include "funcs.h"
#include "log.h"

void swap (log* first_struct_elem, log* second_struct_elem) {
    log tmp = *first_struct_elem;
    *first_struct_elem = *second_struct_elem;
    *second_struct_elem = tmp;
}

void shaker_sort (log* array, int length, int(*compare)(const void*, const void*)) {
    int left = 0, right = length - 1;
    int flag = 1;
    while ((left < right) && flag == 1) {
        flag = 0;
        for (int i = left; i < right; i++) {
            if (compare(&array[i], &array[i + 1]) > 0) {
                swap(&array[i], &array[i + 1]);
                flag = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (compare(&array[i - 1], &array[i]) > 0) {
                swap(&array[i - 1], &array[i]);
                flag = 1;
            }
        }
        left++;
    }
}

void sift_down(log *array, int root, int bottom, int(*compare)(const void*, const void*)) {
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom) {
            maxChild = root * 2;
        } else if (compare(&array[root * 2], &array[root * 2 + 1]) > 0) {
            maxChild = root * 2;
        } else {
            maxChild = root * 2 + 1;
        }
        if (compare(&array[maxChild], &array[root]) > 0) {
            swap(&array[root], &array[maxChild]);
            root = maxChild;
        }
        else {
            done = 1;
        }
    }
}

void heap_sort (log* array, int size, int(*compare)(const void*, const void*)) {
    for (int i = size / 2; i >= 0; i--) {
        sift_down(array, i, size - 1, compare);
    }
    for (int i = size - 1; i >= 1; i--) {
        swap(&array[0], &array[i]);
        sift_down(array, 0, i - 1, compare);
    }
}

