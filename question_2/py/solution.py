#!/usr/bin/env python3
"""Python solution to DNA bacteria problem
"""


def bacterial_dna(n: int, dna_strings: str):
    """
    bacterial_dna: - function that solves the dna bacteria problem
    @params:
        - n: number of test cases {int}
        - dna_strings: 2 dna strings seperated by a space {str}
    """
    count = 0
    if 1 <= n and n <= 100:
        # continue
        dna = dna_strings.split(' ')
        sample_dna = dna[0]
        reference_dna = dna[1]
        if len(sample_dna) == len(reference_dna):
            for char, chars in zip(sample_dna, reference_dna):
                if char != chars:
                    count += 1
    return count

print(bacterial_dna(3, 'TTCGATCCATTG ATCAATCGATCG'))
print(bacterial_dna(3, 'ATTGCC TTAGGC'))
print(bacterial_dna(3, 'TTCGATCCATTG TAGGTAGCTGCC'))
