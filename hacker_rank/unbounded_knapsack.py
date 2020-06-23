#!/bin/python3

# https://www.hackerrank.com/challenges/unbounded-knapsack/problem

import math
import os
import random
import re
import sys

# Complete the unboundedKnapsack function below.
def unboundedKnapsack(k, arr):
    n = len(arr)
    dp = n*[(k+1)*[0]]
    for i in range(n):
        for w in range(k+1):
            a = dp[i][w-arr[i]] + arr[i] if w-arr[i]>=0 else 0
            if a == k: return k
            if a> k:
                a = dp[i][w-arr[i]]
            b = dp[i-1][w] if i-1 >=0 else 0
            dp[i][w] = max(a, b)
    return dp[n-1][k]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    while t:
        nk = input().split()

        n = int(nk[0])

        k = int(nk[1])

        arr = list(map(int, input().rstrip().split()))

        result = unboundedKnapsack(k, arr)

        fptr.write(str(result) + '\n')
        t-=1

    fptr.close()
