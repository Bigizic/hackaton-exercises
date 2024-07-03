#include "main.h"
//#include <stdio.h>
//#include <stdbool.h>

bool vagina_number_checker(int number, char *first, char *second);

/**
* vagina_number_checker - function that checks if a number is a valid vagina number using recursion

* @number: <int> number to perfrom check on
* @first: <string> reference to the first character in number
* @second: <string> reference to the second character in number

* Return: True if number is valid vagina number otherwise False
 */
bool vagina_number_checker(int number, char *first, char *second) {
    char str[4];
    snprintf(str, sizeof(str), "%d", number);
    char *f = &str[0], *s = &str[1], *last = &str[2];

    if (first && second) {
        return atoi(first) * atoi(second) == atoi(last) ? true : false;
    }
    return vagina_number_checker(number, f, s);
}


/**
* main - entry point

*@N: <int> input number to find the smallest
 */
int main(void)
{
    printf("%d\n", vagina_number_checker(300, NULL, NULL) == true ? 1 : 0);
    return 0;
}

