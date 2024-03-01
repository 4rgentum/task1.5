#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int identifier;
	int importance_level;
} log;

int main() {
    FILE *file;
    log str[11];
    file = fopen("input_data.txt", "w");
    srand(rand());
    for (int i = 0; i < 10; i++) {
        str[i].identifier = rand();
        str[i].importance_level = rand() % 5;
        int length = rand() % 100;
        char arr[length + 1];
        for (int j = 0; j < length; j++) {
            arr[j] = rand() % 95 + ' ';
        }
        fprintf(file, "%d %d %s\n", str[i].identifier, str[i].importance_level, arr);
    }
    fclose(file);
}
