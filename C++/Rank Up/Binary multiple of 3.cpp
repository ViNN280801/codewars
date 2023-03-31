// Task: In this kata, your task is to create a regular expression capable of
// evaluating binary strings (strings with only 1s and 0s) and determining whether
// the given string represents a number divisible by 3.

// Take into account that:
// An empty string might be evaluated to true (it's not going to be tested, so you don't
// need to worry about it - unless you want)
// The input should consist only of binary digits - no spaces,
// other digits, alphanumeric characters, etc.
// There might be leading 0s.

// Examples (Javascript):
// multipleof3Regex.test('000') should be true
// multipleof3Regex.test('001') should be false
// multipleof3Regex.test('011') should be true
// multipleof3Regex.test('110') should be true
// multipleof3Regex.test(' abc ') should be false

// You can check more in the example test cases

// Note:
// There's a way to develop an automata (FSM) that evaluates if
// strings representing numbers in a given base are divisible by a given number.
// You might want to check an example of an automata for doing this same particular task here.
// If you want to understand better the inner principles behind it, you might want
// to study how to get the modulo of an arbitrarily large number taking one digit at a time.

#include <iostream>
#include <string>
#include <bitset>

const std::string multiple_of_3_regex = "(1(01*0)*1|0)*";

// Answer from the stackoverflow: https://stackoverflow.com/questions/7974655/regex-for-binary-multiple-of-3
// The simplest one, using only state A, is:
// 0*

// Including state B:
// 0*(11)*0*

// Including state C:
// 0*(1(01*0)*1)*0*

// And include the fact that after going back to state A, the whole process can be started again.
// 0*((1(01*0)*1)*0*)*

// Using some basic regex rules, this simplifies to
// (1(01*0)*1|0)*

// Top 1 in answers to this kata:
// https://math.stackexchange.com/questions/140283/why-does-this-fsm-accept-binary-numbers-divisible-by-three
// Eliminate C: transition from B to B becomes: t = 01*0
// Eliminate B: transition from A to A via B becomes: T = 1t*1
// Single transition from A to A via B or not: r = 0|T*
// Result is transition from A (initial) to A (final) any number of times: R = r*
const std::string multiple_of_3_regex_v2 = "(0|(1(01*0)*1)*)*";

int main()
{
    size_t count{};
    for (size_t i{1}; i <= 600; i++)
    {
        if (i % 3 == 0)
        {
            std::cout << std::bitset<16>(i) << std::endl;
            count++;
        }
    }
    std::cout << "Count = " << count << std::endl;

    return EXIT_SUCCESS;
}
