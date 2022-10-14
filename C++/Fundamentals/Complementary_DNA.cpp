// Task: Deoxyribonucleic acid (DNA) is a chemical found in the nucleus of cells
// and carries the "instructions" for the development and functioning of living organisms.

// If you want to know more: http://en.wikipedia.org/wiki/DNA
// In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G".
// Your function receives one side of the DNA (string, except for Haskell);
// you need to return the other complementary side. DNA strand is never
// empty or there is no DNA at all (again, except for Haskell).
// More similar exercise are found here: http://rosalind.info/problems/list-view/ (source)

// Example: (input --> output)
// "ATTGC" --> "TAACG"
// "GTAT" --> "CATA"

#include <iostream>
#include <string>

// Returns opposite cell from specified cell of DNA
char get_DNA_cell(char &__cell)
{
    if (__cell == 'A')
        __cell = 'T';
    else if (__cell == 'T')
        __cell = 'A';
    else if (__cell == 'C')
        __cell = 'G';
    else if (__cell == 'G')
        __cell = 'C';

    return __cell;
}

// Returns pair of specified '__dna' DNA
std::string DNAStandard(const std::string &__dna)
{
    std::string dna_pair{__dna};

    for (size_t index{0UL}; index < dna_pair.size(); index++)
    {
        get_DNA_cell(dna_pair.at(index));
    }

    return dna_pair;
}

int main()
{
    std::string dna{DNAStandard("AAAA")};
    std::cout << dna << std::endl;

    dna = DNAStandard("ATTGC");
    std::cout << dna << std::endl;

    dna = DNAStandard("GTAT");
    std::cout << dna << std::endl;

    return EXIT_SUCCESS;
}
