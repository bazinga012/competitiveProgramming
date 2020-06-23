#!/bin/python3

import math
import os
import random
import re
import sys
# https://www.hackerrank.com/challenges/jim-and-the-orders/problem

# Complete the jimOrders function below.
def jimOrders(orders):
    if not orders: return orders
    d_orders = [(order[0] + order[1], idx) for idx, order in enumerate(orders)]
    d_orders.sort()
    return [d[1]+1 for d in d_orders]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    orders = []

    for _ in range(n):
        orders.append(list(map(int, input().rstrip().split())))

    result = jimOrders(orders)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
