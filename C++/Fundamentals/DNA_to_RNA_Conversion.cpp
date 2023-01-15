// Task: Deoxyribonucleic acid, DNA is the primary information storage molecule in
// biological systems. It is composed of four nucleic acid bases Guanine ('G'), Cytosine ('C'), Adenine ('A'), and Thymine ('T').
// Ribonucleic acid, RNA, is the primary messenger molecule in cells. RNA differs slightly
// from DNA its chemical structure and contains no Thymine. In RNA Thymine is replaced by
// another nucleic acid Uracil ('U').
// Create a function which translates a given DNA string into RNA.

// For example:
// "GCAT"  =>  "GCAU"

// The input string can be of arbitrary length - in particular, it may be empty.
// All input is guaranteed to be valid, i.e. each input string will only ever consist of 'G', 'C', 'A' and/or 'T'.

#include <iostream>
#include <algorithm>
#include <string>

// Returns string where timin (T) is replaced by uracil (U)
std::string DNAtoRNA(const std::string &__DNA)
{
    std::string RNA(__DNA);

    if (__DNA.empty())
        return "";

    std::replace_if(
        std::begin(RNA), std::end(RNA), [](const char &ch)
        { return ch == 'T'; },
        'U');

    return RNA;
}

int main()
{
    std::cout << DNAtoRNA("GCAT") << std::endl;

    return EXIT_SUCCESS;
}
