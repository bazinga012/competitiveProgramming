# Queue - synchronised queue
# uses deque in the background
from queue import Queue

q = Queue(maxsize=10)

# Deque
# https://stackoverflow.com/questions/58152201/time-complexity-deleting-element-of-deque
from collections import deque

nq = deque()
nq.append(4)
nq.append(15)
del nq[1]
print(q) # deque([4])
