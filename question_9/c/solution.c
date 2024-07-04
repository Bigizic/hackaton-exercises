#include "main.h"

bool vagina_number_checker(int number, char *first, char *second);
int vagina_main(int N, bool first_check, bool second_check, int count,
                int result);

/**
* vagina_number_checker - function that checks if a number is a valid vagina number using recursion
*
* @number: <int> number to perfrom check on
* @first: <string> reference to the first character in number
* @second: <string> reference to the second character in number
*
* Return: True if number is valid vagina number otherwise False
 */
bool vagina_number_checker(int number, char *first, char *second) {
    char str[4];
    snprintf(str, sizeof(str), "%d", number);
    size_t length = strlen(str);
    if (length != 3) {
        return false;
    };
    char *f = &str[0], *s = &str[1], *last = &str[2];

    if (first && second) {
        return atoi(first) * atoi(second) == atoi(last) ? true : false;
    }
    return vagina_number_checker(number, f, s);
}


/**
* vagina_main - entry point
*
* @N: <int> input number to find the smallest
* @first_check: <bool>
* @second_check: <bool>
* @count: <int>
* @result: <int>
*
* Return: smallest vagina number that is greater than or equal to N
 */
int vagina_main(int N, bool first_check, bool second_check,
         int count, int result)
{
    if (100 <= N && N <= 919) {
        if (first_check && second_check) {
            return result;
        };

        if (!vagina_number_checker(N, NULL, NULL) && count == 0) {
            return vagina_main(N + 1, NULL, NULL, count, result);
        };

        if (!vagina_number_checker(N, NULL, NULL) && count > 0) {
            return vagina_main(N + 1, first_check, NULL, count, result);
        };

        if (vagina_number_checker(N, NULL, NULL) && count > 0) {
            return vagina_main(N + 1, true, true, count + 1, result);
        };

        if (vagina_number_checker(N, NULL, NULL)) {
            return vagina_main(N + 1, true, NULL, count + 1, N);
        };
    };
    return 0;
}

/**
* main - entry point
*
* Return: 0
 */
int main(void) {
    int numbers[5] = {320, 144, 516, 122, 100};

    for (int i = 0; i < sizeof(numbers); i++) {
        printf("%d\n", vagina_main(numbers[i], NULL, NULL, '\0', '\0'));
    };
    return 0;
}

