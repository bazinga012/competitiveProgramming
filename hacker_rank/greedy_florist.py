# https://www.hackerrank.com/challenges/greedy-florist/problem
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the getMinimumCost function below.
def getMinimumCost(k, c):
    c.sort(key=lambda x: -x)
    total = 0
    j = 0
    purchase_number = 1
    for i in c:
        if j==k:
            j=0
            purchase_number+=1
        total += (purchase_number*i)
        j+=1
    return total

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    c = list(map(int, input().rstrip().split()))

    minimumCost = getMinimumCost(k, c)

    fptr.write(str(minimumCost) + '\n')

    fptr.close()
