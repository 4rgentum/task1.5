#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <getopt.h>
#include "log.h"
#include "funcs.h"

int main(int argc, char **argv) {
    int size = 0;
    srand(time(NULL));
    int flag = 0;
    char *sorting = NULL, *field = NULL, *orientation = NULL, *size_of_log = NULL, *number_of_sorting = NULL;
    while ((flag = getopt(argc, argv, "QSHLICUDs:n:")) != -1) {
        switch (flag) {
            case 'Q':
                sorting = "Q";
                break;
            case 'S':
                sorting = "S";
                break;
            case 'H':
                sorting = "H";
                break;
            case 'L':
                field = "L";
                break;
            case 'I':
                field = "I";
                break;
            case 'C':
                field = "C";
                break;
            case 'U':
                orientation = "U";
                break;
            case 'D':
                orientation = "D";
                break;
            case 's':
                size_of_log = optarg;
                break;
            case 'n':
                number_of_sorting = optarg;
                break;
            case '?':
                printf("This Is Wrong Argument.\n");
                return 1;
        }
    }
    if (sorting == NULL || field == NULL || orientation == NULL || size_of_log == NULL || number_of_sorting == NULL) {
        printf("Put Some Arguments\n");
        return 2;
    }
    log *stroka;
    for (int i = 0; i < strlen(size_of_log); i++) {
        size = size * 10 + (size_of_log[i] - '0');
    }
    int sorting_counter = 0;
    for (int i = 0; i < strlen(number_of_sorting); i++) {
        sorting_counter = sorting_counter * 10 + (number_of_sorting[i] - '0');
    }
    double time_spent = 0.0;
    stroka = calloc(size, sizeof(log));
    for (int counter = 0; counter < sorting_counter; counter++) {
        for (int i = 0; i < size; i++) {
            stroka[i].identifier = rand() % 100;
            stroka[i].importance_level = rand() % 5;
            int length = rand() % 100;
            char arr[length + 1];
            for (int j = 0; j < length; j++) {
                arr[j] = rand() % 95 + ' ';
            }
            stroka[i].string = calloc(length + 1, sizeof(char));
            for (int j = 0; j < length; j++) {
                stroka[i].string[j] = arr[j];
            }
        }
        clock_t begin = clock();
        if (sorting == "Q") {
            if (field == "I") {
                if (orientation == "U") {
                    qsort(stroka, size, sizeof(log), (int (*)(const void *, const void *)) identifier_comparator);
                } else if (orientation == "D") {
                    qsort(stroka, size, sizeof(log),
                          (int (*)(const void *, const void *)) identifier_comparator_reverse);
                }
            } else if (field == "L") {
                if (orientation == "U") {
                    qsort(stroka, size, sizeof(log), (int (*)(const void *, const void *)) importance_level_comparator);
                } else if (orientation == "D") {
                    qsort(stroka, size, sizeof(log),
                          (int (*)(const void *, const void *)) importance_level_comparator_reverse);
                }
            } else if (field == "C") {
                if (orientaion == "U") {
                    qsort(stroka, size, sizeof(log), (int (*)(const void *, const void *)) string_comparator);
                } else if (orientation == "D") {
                    qsort(stroka, size, sizeof(log), (int (*)(const void *, const void *)) string_comparator_reverse);
                }
            }
        } else if (sorting == "S") {
            if (field == "I") {
                if (orientation == "U") {
                    shaker_sort(stroka, size, (int (*)(const void *, const void *)) identifier_comparator);
                } else if (orientation == "D") {
                    shaker_sort(stroka, size, (int (*)(const void *, const void *)) identifier_comparator_reverse);
                }
            } else if (field == "L") {
                if (orientation == "U") {
                    shaker_sort(stroka, size, (int (*)(const void *, const void *)) importance_level_comparator);
                } else if (orientation == "D") {
                    shaker_sort(stroka, size,
                                (int (*)(const void *, const void *)) importance_level_comparator_reverse);
                }
            } else if (field == "C") {
                if (orientation == "U") {
                    shaker_sort(stroka, size, (int (*)(const void *, const void *)) string_comparator);
                } else if (orientation == "D") {
                    shaker_sort(stroka, size, (int (*)(const void *, const void *)) string_comparator_reverse);
                }
            }
        } else if (sorting == "H") {
            if (field == "I") {
                if (orientation == "U") {
                    heap_sort(stroka, size, (int (*)(const void *, const void *)) identifier_comparator);
                } else if (orientation == "D") {
                    heap_sort(stroka, size, (int (*)(const void *, const void *)) identifier_comparator_reverse);
                }
            } else if (field == "L") {
                if (orientation == "U") {
                    heap_sort(stroka, size, (int (*)(const void *, const void *)) importance_level_comparator);
                } else if (orientation == "D") {
                    heap_sort(stroka, size, (int (*)(const void *, const void *)) importance_level_comparator_reverse);
                }
            } else if (field == "C") {
                if (orientation == "U") {
                    heap_sort(stroka, size, (int (*)(const void *, const void *)) string_comparator);
                } else if (orientation == "D") {
                    heap_sort(stroka, size, (int (*)(const void *, const void *)) string_comparator_reverse);
                }
            }
        }
        clock_t end = clock();
        time_spent += (double) (end - begin) / CLOCKS_PER_SEC;
        for (int k = 0; k < size; ++k) {
            free(stroka[k].string);
        }
    }
    time_spent /= sorting_counter;
    free(stroka);
    printf("Time Of %s Sorting Of %d structs: %lf seconds\n", sorting, size, time_spent);
    return 0;

