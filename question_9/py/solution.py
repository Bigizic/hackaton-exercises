#!/usr/bin/env python3
"""Solutuon to vagina number using recursion
"""


def vagina_number_checker(number: int, f: str = None, s: str = None) -> bool:
    """Function that checks if a number is a vagina number
    Params:
        - number: <int> number to check if it's a valid vagina
        - f: <str> first digit in number assuming number is only 3 digit
        - s: <str> second digit in number assuming number is only 3 digit

    Return:
        - True if number is a valid vagina otherwise false
    """
    # assume all numbmers have a length of 3
    N = str(number)
    if len(N) != 3:
        return False
    if f and s:
        return True if int(f) * int(s) == int(N[2]) else False

    return vagina_number_checker(int(N), N[0], N[1])


def main(N: int, first_check: bool = None, second_check: bool = None,
         count: int = 0, res: int = None) -> int:
    """Entry point to solution
    params:
        - N: <int> input

    Return:
        - Following the Constraints 100≤N≤919 returns the smallest vagina
        - number that is greater than of equal to N
    """
    if 100 <= N and N <= 919:
        # continue
        if first_check and second_check:
            return res

        if not vagina_number_checker(N) and count == 0:
            return main(N + 1, None, None, count, res)

        if not vagina_number_checker(N) and count > 0:
            return main(N + 1, first_check, None, count, res)

        if vagina_number_checker(N) and count > 0:
            return main(N + 1, True, True, count + 1, res)

        if vagina_number_checker(N):
            # first check if N is vagina equals true
            return main(N + 1, True, None, count + 1, N)
    return False


print(main(320))
print(main(144))
print(main(516))
print(main(122))
print(main(100))

"""
main(224)
print("\n")
main(287)
main(473)
main(112)
"""
