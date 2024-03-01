#include <stdio.h>
#include <string.h>
#include "log.h"

int identifier_comparator (const log* first_struct_elem, const log* second_struct_elem) {
    return first_struct_elem->identifier - second_struct_elem->identifier;
}

int identifier_comparator_reverse (const log* first_struct_elem, const log* second_struct_elem) {
    return second_struct_elem->identifier - first_struct_elem->identifier;
}

int importance_level_comparator (const log* first_struct_elem, const log* second_struct_elem) {
    return first_struct_elem->importance_level - second_struct_elem->importance_level;
}

int importance_level_comparator_reverse (const log* first_struct_elem, const log* second_struct_elem) {
    return second_struct_elem->importance_level - first_struct_elem->importance_level;
}

int string_comparator (const log* first_struct_elem, const log* second_struct_elem) {
    if (strlen(first_struct_elem->string) == strlen(second_struct_elem->string)){
	return strcmp(first_struct_elem->string, second_struct_elem->string);
    } else {
	    if (strlen(first_struct_elem->string) > strlen(second_struct_elem->string)){
		    return 1;
	    } else if (strlen(first_struct_elem->string) < strlen(second_struct_elem->string)) {
		    return -1;
	    }
    }
}

int string_comparator_reverse (const log* first_struct_elem, const log* second_struct_elem) {
    if (strlen(first_struct_elem->string) == strlen(second_struct_elem->string)) {
	return strcmp(second_struct_elem->string, first_struct_elem->string);
    } else {
	    if (strlen(first_struct_elem->string) < strlen(second_struct_elem->string)) {
		    return 1;
	    } else if (strlen(first_struct_elem->string) > strlen(second_struct_elem->string)) {
		    return -1;
	    }
    }
}

