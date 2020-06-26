# https://www.youtube.com/watch?v=qQ8vS2btsxI
def rabin_karp_search(T, P, alphabet):
    d = len(alphabet)  # size of alphabet
    q = 113  # some prime
    m = len(P)  # length of pattern
    n = len(T)  # len of text
    h = 1  # math.pow(d, m-1)

    # if d = 10
    # hash(abc, m=2, d=10) = 10^2 * a + 10^1 * b + 10^0 *c
    # hash(abc, m=2, d) = d^2 * a + d^1 * b + d^0 * c

    # rolling hash
    # hash value of string [i+1,i+m] from hash value of [i, i+m-1]
    # prev_hash = hash value of [i, i+m-1] # i will be removed from current window and i+m will be included in current window
    # next_hash = (prev_hash - T[i]*(math.pow(d, m-1)))*d + T[i+m]
    # T[i] = int value of char at ith index in T

    # hash values and powers can be very huge and can result in overflows so we take q(a prime) for taking modulus

    # math.pow(d, m-1) can be calculated once and stored in a variable h.
    # since this can be a huge value need to take mod with q
    for i in range(1, m):
        h = (h * d) % q

    patten_hash_value = 0
    curr_window_hash = 0
    for i in range(m):
        # for understanding try for a, ab, abc and take d as 10
        patten_hash_value = (d * patten_hash_value + ord(P[i])) % q
        curr_window_hash = (d * curr_window_hash + ord(T[i])) % q

    if patten_hash_value == curr_window_hash and T[0:m] == P:
        print("pattern found at index 0")

    for i in range(m, n):
        # i-m will go out of window i will come in window
        curr_window_hash = ((curr_window_hash - (ord(T[i - m]) * h)) * d + ord(T[i])) % q
        if curr_window_hash < 0:
            curr_window_hash += q
        if patten_hash_value == curr_window_hash and T[i - m + 1:i + 1] == P:
            print("pattern found at index %s" % (i - m + 1))


def rabin_karp(T, P, alphabet_size):
    n, m, d = len(T), len(P), alphabet_size
    q = 101
    h = 1
    for i in range(1, m):
        h = (h * d) % q

    current_window_hash = 0
    pattern_hash = 0
    for i in range(m):
        current_window_hash = (d * current_window_hash + ord(T[i])) % q
        pattern_hash = (d * pattern_hash + ord(P[i])) % q

    if current_window_hash == pattern_hash and T[0:m] == P:
        print("pattern found at %s" % (0))

    for i in range(m, n):
        current_window_hash = ((current_window_hash - h * ord(T[i - m])) * d + ord(T[i])) % q
        if current_window_hash < 0:
            current_window_hash += q

        if current_window_hash == pattern_hash and T[(i - m + 1):(i + 1)] == P:
            print("pattern found at %s" % (i - m + 1))
