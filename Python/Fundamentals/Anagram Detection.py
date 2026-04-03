# https://stackoverflow.com/questions/567222/simple-prime-number-generator-in-python
def gen_primes():
    """ Generate an infinite sequence of prime numbers.
    """
    # Maps composites to primes witnessing their compositeness.
    # This is memory efficient, as the sieve is not "run forward"
    # indefinitely, but only as long as required by the current
    # number being tested.
    #
    D = {}

    # The running integer that's checked for primeness
    q = 2

    while True:
        if q not in D:
            # q is a new prime.
            # Yield it and mark its first multiple that isn't
            # already marked in previous iterations
            #
            yield q
            D[q * q] = [q]
        else:
            # q is composite. D[q] is the list of primes that
            # divide it. Since we've reached q, we no longer
            # need it in the map, but we'll mark the next
            # multiples of its witnesses to prepare for larger
            # numbers
            #
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]

        q += 1

PRIME_GENERATOR = gen_primes()
CHAR_MAP = {chr(i): next(PRIME_GENERATOR) for i in range(ord('a'), ord('z') + 1)}

def is_anagram(test: str, original: str) -> bool:
    str_size = len(test)

    if str_size != len(original):
        return False

    if str_size == 0:
        return True

    if not test.isalpha() or not original.isalpha():
        return False

    test = test.lower()
    original = original.lower()

    if (str_size == 1) and (test == original):
        return True

    test_product = 1
    original_product = 1

    for ch in test:
        test_product *= CHAR_MAP[ch]
    for ch in original:
        original_product *= CHAR_MAP[ch]

    return test_product == original_product

def main():
    assert is_anagram("", "") == True
    assert is_anagram("a", "A") == True
    assert is_anagram("a", "T") == False
    assert is_anagram("34gdsfg", "re4g65h") == False
    assert is_anagram("ab", "ba") == True
    assert is_anagram("abc", "ab") == False
    assert is_anagram("aab", "aba") == True
    assert is_anagram("creaTIVE", "REActive") == True
    assert is_anagram("Silent", "LISTeN") == True
    assert is_anagram("uubbta", "bbuutb") == False
    assert is_anagram("IOoo2e", "2EoooA") == False

if __name__ == "__main__":
    main()

# =============================================================================
# Approach: Prime Number Product (Mathematical / Number Theory)
# =============================================================================
#
# Core idea:
#   Assign a unique prime number to each letter of the alphabet (a=2, b=3,
#   c=5, ..., z=101). Compute the product of primes for each string. Two
#   strings are anagrams if and only if their products are equal.
#
# Correctness relies on the Fundamental Theorem of Arithmetic:
#   Every integer > 1 has a unique prime factorisation. Therefore, two
#   products are equal iff the multisets of their prime factors are
#   identical — which is exactly the definition of an anagram.
#
# Complexity analysis:
#   Let n = len(test) = len(original)  (early exit if lengths differ)
#   Let P = value of the largest prime assigned (101 for 'z')
#
#   Time complexity: O(n * M(n))
#     - Two linear passes to build the products:        O(n) iterations
#     - Each multiplication: the product grows as P^k after k steps,
#       requiring O(k * log P) bits. Multiplying a k-digit number by a
#       constant-size prime costs O(k) = O(log(P^k)) per step.
#       Summing over all n steps: O(1 + 2 + ... + n) = O(n^2) bit ops.
#     - Final comparison of two O(n log P)-bit integers: O(n).
#     - Overall: O(n^2) in terms of bit operations.
#     - If we treat big-integer arithmetic as O(1) (i.e. count only
#       Python-level operations, as is conventional in algorithm courses),
#       the complexity reduces to O(n).
#
#   Space complexity: O(n)
#     - CHAR_MAP: 26 entries, each a small prime — O(1).
#     - test_product / original_product: each grows to O(n log P) bits
#       as characters are accumulated — O(n) bits total.
#     - Input strings after .lower(): O(n).
#     - Overall: O(n).
#
# Practical limitations:
#   For a string of length n composed entirely of 'z' (prime 101):
#     product ≈ 101^n  →  bit length ≈ n * log2(101) ≈ 6.66 * n bits.
#   At n = 10^9: ~830 MB just to store one product — clearly impractical.
#
# Comparison with the frequency-count approach (array/hash-table):
#   ┌─────────────────────┬──────────────────┬──────────────────┐
#   │                     │  Prime product   │  Frequency count │
#   ├─────────────────────┼──────────────────┼──────────────────┤
#   │ Time  (word ops)    │ O(n)             │ O(n)             │
#   │ Time  (bit ops)     │ O(n²)            │ O(n)             │
#   │ Space               │ O(n)             │ O(1) *           │
#   │ Elegance            │ high             │ moderate         │
#   │ Practicality        │ poor for large n │ excellent        │
#   └─────────────────────┴──────────────────┴──────────────────┘
#   * O(1) space for fixed alphabet size (26 letters).
#
# Verdict:
#   An elegant number-theory trick with clean O(n) word-level complexity,
#   but the frequency-count approach dominates in practice due to O(1)
#   space and true O(n) bit-level time.
# =============================================================================

