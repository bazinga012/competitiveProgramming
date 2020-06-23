# https://www.hackerrank.com/challenges/is-fibo/problem
# Complete the solve function below.
import math


def solve(n):
    n_sq = n*n
    val = 5*n_sq + 4
    int_sqrt = int(math.sqrt(val))
    if int_sqrt*int_sqrt == val:
        return "IsFibo"

    val = 5*n_sq - 4
    int_sqrt = int(math.sqrt(val))
    if int_sqrt*int_sqrt == val:
        return "IsFibo"

    return "IsNotFibo"
