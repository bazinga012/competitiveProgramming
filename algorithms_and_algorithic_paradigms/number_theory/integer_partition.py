# https://en.wikipedia.org/wiki/Partition_(number_theory)#:~:text=In%20number%20theory%20and%20combinatorics,are%20considered%20the%20same%20partition.
""" 
    In number theory and combinatorics, a partition of a positive integer n, also called an integer partition, 
    is a way of writing n as a sum of positive integers. Two sums that differ only in the order of their summands 
    are considered the same partition. (If order matters, the sum becomes a composition.) 

    1) The partition function p(n) represents the number of possible partitions of a non-negative integer n.

    2)  If we flip the diagram( Young diagrams or Ferrers diagrams ) of the partition along its main diagonal, we obtain another 
        partition we call these two partitions conjugate of each other.
        
        If both are same we call them self-conjugate.
        
        Claim: The number of self-conjugate partitions is the same as the number of partitions with distinct odd parts.
        Proof (outline): The crucial observation is that every odd part can be "folded" in the middle to form a self-conjugate.
    
    3)  For each positive number, the number of partitions with odd parts equals the number of partitions with distinct parts, 
        denoted by q(n).

    4)  By taking conjugates, the number p(n, k) of partitions of n into exactly k parts is equal to the number of partitions 
        of n in which the largest part has size k. The function p(n) satisfies the recurrence

        p(n, k) = p(n − k, k) + p(n − 1, k - 1)
        with initial values p0(0) = 1 and pk(n) = 0 if n ≤ 0 or k ≤ 0 and n and k are not both zero.

    5) Let p(N, M; n) denote the number of partitions of n with at most M parts, each of size at most N.
    Equivalently, these are the partitions whose Young diagram fits inside an M × N rectangle.
    
    p(N, M; n) = p(N, M-1; n) + p(N-1, M; n-M)

    obtained by observing that 
        a) p(N,M;n) - p(N,M-1;n) counts the partitions of n into exactly M parts of size at most N
        b) and subtracting 1 from each part of such a partition yields a partition of n − M into at most M parts.
"""

dp = {}


def custom_call(n, k, l=1):
    global dp
    key = f"{n}-{k}-{l}"
    if key in dp:
        return dp[key]
    if k < 1:
        return 0
    if k == 1:
        if n >= l:
            return 1
    p = 0
    for i in range(l, n+1):
        p += custom_call(n-i, k-1, i)
    dp[key] = p
    return p


dp = {}


def f(n, k):
    global dp
    key = f"{n} - {k}"
    if key in dp:
        return dp[key]
    if n == 0 and k == 0:
        return 1
    if n <= 0 or k <= 0:
        return 0
    a = f(n-k, k)
    b = f(n - 1, k-1)
    dp[key] = a+b
    return dp[key]
