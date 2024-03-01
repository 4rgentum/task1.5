#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "log.h"
#include "funcs.h"

char* my_readline(FILE* file) {
    char buffer[81] = {0};
    char *my_string = NULL;
    int length = 0;
    int element = 0;
    do {
        int flag = 0;
        element = fscanf(file, "%80[^\n]%n", buffer, &flag);
        if (element < 0) {
            if (!my_string) {
                return 0;
            }
        } else if (element > 0) {
            int chunk_len = strlen(buffer);
            int str_len = length + chunk_len;
            my_string = realloc(my_string, str_len + 1);
            memcpy(my_string + length, buffer, chunk_len);
            length = str_len;
            my_string[str_len] = '\0';
        } else {
            fscanf(file, "%*1[\n]");
        }
    } while (element > 0);
    if (length > 0) {
        my_string[length] = '\0';
        return my_string;
    } else {
        my_string = calloc(1, sizeof(char));
        return 0;
    }
}

int main(int argc, char **argv){
    log *stroka;
    int size = 0;
    int flag = 0;
    char* sorting = NULL, *field = NULL, *orientation = NULL, *in = NULL, *out = NULL;
    while((flag = getopt(argc, argv, "QSHLICUDi:o:")) != -1){
        switch(flag){
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
            case 'i':
                in = optarg;
                break;
            case 'o':
                out = optarg;
                break;
            case '?':
                printf("This Is Wrong Argument.\n");
                return 1;
        }
    }
    if (sorting == NULL || field == NULL || orientation == NULL || in == NULL || out == NULL){
        printf("Put Some Arguments\n");
        return 2;
    }
    FILE *input_data = fopen(in, "r");
    if (!input_data){
        printf("These File Can't Be Open\n");
        return 3;
    }
    FILE *output_data = fopen(out, "w");
    if (!output_data){
        fclose(input_data);
        printf("These File Can't Be Open\n");
        return 3;
    }
    stroka = calloc(15001, sizeof(log));
    while(!feof(input_data)){
        fscanf(input_data, "%d", &(stroka[size].identifier));
        fscanf(input_data, "%d", &(stroka[size].importance_level));
        stroka[size].string = my_readline(input_data);
        fscanf(input_data, "%*1[\n]");
        ++size;
    }
    if (sorting == "Q") {
        if (field == "I") {
            if (orientation == "U") {
                qsort(stroka, size, sizeof(log), (int (*)(const void *, const void *)) identifier_comparator);
            }
            else if (orientation == "D") {
                qsort(stroka, size, sizeof(log), (int (*)(const void *, const void *)) identifier_comparator_reverse);
            }
        }
        else if (field == "L") {
            if (orientation == "U") {
                qsort(stroka, size, sizeof(log), (int (*)(const void *, const void *)) importance_level_comparator);
            }
            else if (orientation == "D") {
                qsort(stroka, size, sizeof(log), (int (*)(const void *, const void *)) importance_level_comparator_reverse);
            }
        }
        else if (field == "C") {
            if (orientation == "U") {
                qsort(stroka, size, sizeof(log), (int (*)(const void *, const void *)) string_comparator);
            }
            else if (orientation == "D") {
                qsort(stroka, size, sizeof(log), (int (*)(const void *, const void *)) string_comparator_reverse);
            }
        }
    }
    else if (sorting == "S") {
        if (field == "I") {
            if (orientation == "U") {
                shaker_sort(stroka, size, (int (*)(const void *, const void *)) identifier_comparator);
            }
            else if (orientation == "D") {
                shaker_sort(stroka, size, (int (*)(const void *, const void *)) identifier_comparator_reverse);
            }
        }
        else if (field == "L") {
            if (orientation == "U") {
                shaker_sort(stroka, size, (int (*)(const void *, const void *)) importance_level_comparator);
            }
            else if (orientation == "D") {
                shaker_sort(stroka, size, (int (*)(const void *, const void *)) importance_level_comparator_reverse);
            }
        }
        else if (field == "C") {
            if (orientation == "U") {
                shaker_sort(stroka, size, (int (*)(const void *, const void *)) string_comparator);
            }
            else if (orientation == "D") {
                shaker_sort(stroka, size, (int (*)(const void *, const void *)) string_comparator_reverse);
            }
        }
    }
    else if (sorting == "H") {
        if (field == "I") {
            if (orientation == "U") {
                heap_sort(stroka, size, (int (*)(const void *, const void *)) identifier_comparator);
            }
            else if (orientation == "D") {
                heap_sort(stroka, size, (int (*)(const void *, const void *)) identifier_comparator_reverse);
            }
        }
        else if (field == "L") {
            if (orientation == "U") {
                heap_sort(stroka, size, (int (*)(const void *, const void *)) importance_level_comparator);
            }
            else if (orientation == "D") {
                heap_sort(stroka, size, (int (*)(const void *, const void *)) importance_level_comparator_reverse);
            }
        }
        else if (field == "C") {
            if (orientation == "U") {
                heap_sort(stroka, size, (int (*)(const void *, const void *)) string_comparator);
            }
            else if (orientation == "D") {
                heap_sort(stroka, size, (int (*)(const void *, const void *)) string_comparator_reverse);
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        fprintf(output_data, "%d %d%s\n", stroka[i].identifier, stroka[i].importance_level, stroka[i].string);
        fflush(output_data);
        free(stroka[i].string);
    }
    free(stroka);
    fclose(input_data);
    fclose(output_data);
    return 0;
}
