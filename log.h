#ifndef LOG_H
#define LOG_H

typedef struct {
	int identifier;
	int importance_level;
	char* string;
} log;

int identifier_comparator (const log*, const log*);
int identifier_comparator_reverse (const log*, const log*);
int importance_level_comparator (const log*, const log*);
int importance_level_comparator_reverse (const log*, const log*);
int string_comparator (const log*, const log*);
int string_comparator_reverse(const log*, const log*);

#endif
