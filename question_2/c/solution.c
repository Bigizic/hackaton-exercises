#include "main.h"


/**
* split - splits a string by a delimeter
*
* @string: <string> string to work on
* @delimeter: <string> string splitter
* @list: <char> contains each string splited by the delimeter
* @count: <int> reference the number of times a string has been splitted
*
* Return: void
*/
void spliter(const char *string, char delimiter, char **list, int *count)
{
    char *str = strdup(string);
    char *token;
    int index = 0;

    // ~~~~ strtok to tokenize the string ~~~~
    token = strtok(str, &delimiter);
    while (token != NULL) {
        //~~~~ duplicate the token and store it in the list ~~~~
        list[index++] = strdup(token);
        token = strtok(NULL, &delimiter);
    }
    list[index] = NULL;  // (NULL) terminate the array
    *count = index;  // set the count of tokens

    free(str);  // free the duplicated string
}


/**
* split - splits a string by the delimeter and keeps a count while splitting
*
* @string: <string> string to split
* @delimeter: <string>
* @count: <int> count while string is being splited
*
* Return: list of splited string
*/
char **split(char *string, char *delimeter, int *count)
{
    size_t length = strlen(string);
    char **list = malloc((length / 2 + 1) * sizeof(char *));
    if (list == NULL) {
        perror("malloc failed");
        return NULL;
    }

    spliter(string, *delimeter, list, count);
    return list;
}

/**
* bacterial_dna - solves the bacterial dna problem
*
* @n: <int> number of test cases
*
* @dna_strings: <string> 2 dna steings seperated by a space
*
* Return: <int> indicating the number of nucleotide substitutions required to
*	      change the sample DNA strings (S) to the reference DNA strings (R)
*/
int bacterial_dna(int n, char *dna_strings)
{
	int count = 0;
	char sample_dna, reference_dna;
	int token_count;
	if (n >= 1 && n <= 100) {
		// continue
        char **dna = split(dna_strings, " ", &token_count);
        if (dna == NULL) {
            return -1;
        }

        if (token_count >= 1) {
            char *sample_dna = dna[0];
            char *reference_dna = dna[1];

            if (strlen(sample_dna) == strlen(reference_dna)) {
                for (int i = 0; i < strlen(sample_dna); i++) {
                    if (sample_dna[i] != reference_dna[i]) {
                        count++;
                    }
                }
            }
        }

        for (int i = 0; i < token_count; i++) {
            free(dna[i]);
        }
        free(dna);
    }
    return count;
}


/**
* main - main entry
*
* Return: 0
 */
int main(void) {
	printf("%d\n", bacterial_dna(3, "TTCGATCCATTG ATCAATCGATCG"));
	printf("%d\n", bacterial_dna(3, "ATTGCC TTAGGC"));
	printf("%d\n", bacterial_dna(3, "TTCGATCCATTG TAGGTAGCTGCC"));
	return (0);
}
