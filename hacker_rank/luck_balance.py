#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the luckBalance function below.
def luckBalance(k, contests):
    contests.sort(key=lambda contest: [-contest[1], -contest[0]])
    res = 0
    for idx, contest in enumerate(contests):
        if contest[1] == 0:
            res+=contest[0]
            continue
        if idx < k:
            res+=contest[0]
        else:
            res-=contest[0]
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    contests = []

    for _ in range(n):
        contests.append(list(map(int, input().rstrip().split())))

    result = luckBalance(k, contests)

    fptr.write(str(result) + '\n')

    fptr.close()
