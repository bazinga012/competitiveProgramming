# list and helper functions

# zip()
"""
The zip() function returns an iterator of tuples based on the iterable objects.
a) If we do not pass any parameter, zip() returns an empty iterator
b) If a single iterable is passed, zip() returns an iterator of tuples with each tuple having only one element.
c) If multiple iterables are passed, zip() returns an iterator of tuples with each tuple having elements from all the iterables.

d) Suppose, two iterables are passed to zip(); one iterable containing three and other containing five elements.
Then, the returned iterator will contain three tuples.
It's because iterator stops when the shortest iterable is exhausted.
"""
a = [1, 2, 3, 4, 5]
b = [4, 3, 5, 2, 1]
zip(a).__next__()  # (1,)
zip(a, b).__next__()  # (1, 5)

keys = [1, 2, 3, 4, 5]
values = [4, 3, 5, 2, 1]
dict_from_arrays = {i: j for i, j in zip(keys, values)}
# {1: 4, 2: 3, 3: 5, 4: 2, 5: 1}
# end of zip


# map
map(lambda x, y: print(x + y), [1, 2], [3, 4])
a = [1, 2, 3]
b = [4, 5, 6]
p = map(lambda i, j: print(i, j), a, b)
next(p)  # 1 4
next(p)  # 2 5
next(p)  # 3 6
next(p)  # error StopIteration
for order, it in enumerate(map(iter, [a, b])):
    next(it)


# Utilities
# sort
a = [2, 10, 6, 9, 4, 1, 5]
# If a key function is given, apply it once to each list item and sort them, ascending or descending, according to their function values.
# custom comparison function
def even_odd_sort(x, y):
    if x == y:
        return 0
    x_is_odd = (x & 1)
    y_is_odd = (y & 1)
    if (x_is_odd and y_is_odd) or not (x_is_odd and y_is_odd):
        return x - y
    if x_is_odd:
        return -1
    if y_is_odd:
        return 1


import functools
a.sort(key=functools.cmp_to_key(even_odd_sort))  # odd even sorting
print(a)


# bisect
import bisect
arr = [3, 11, 15, 20, 25, 32]
arr.sort()
bisect.bisect_left(arr, 16) # Ceil index The return value i is such that all e in a[:i] have e < x, and all e in a[i:] have e >= x.


