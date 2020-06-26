# https://www.youtube.com/watch?v=V5-7GzOfADQ
def kmp_lps(s):
    n = len(s)
    if n <= 1: return [0]
    pi = [0] * n
    j = 1
    i = 0
    lps = 0
    while j < n:
        if s[j] == s[i]:
            lps += 1
            pi[j] = lps
            i += 1
        else:
            i = 0
            lps = 0
        j += 1
    return pi


def kmp_search(S, P):
    s_len = len(S)
    p_len = len(P)
    if p_len < 1 or p_len > s_len: return
    pi = kmp_lps(P)
    i, j = 0, -1
    while i < s_len:
        if S[i] == P[j + 1]:
            i += 1
            j += 1
            if j == p_len - 1:
                print("found at index %s" % (i - p_len))
                j = pi[j] - 1
        else:
            if j == -1:
                i += 1
            else:
                j = pi[j] - 1
