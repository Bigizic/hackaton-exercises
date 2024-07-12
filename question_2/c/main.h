#ifndef MAIN_H
#define MAIN_H

/* headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function prototype */
int bacterial_dna(int n, char *dna_strings);
void spliter(const char *string, char delimiter, char **list, int *count);
char **split(char *string, char *delimeter, int *count);

#endif
