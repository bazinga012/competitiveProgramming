def store_two_numbers_in_one_index(arr, idx, second_number, z):
    """if only positive numbers in array. z should be bigger than max of arr"""
    arr[idx] += (second_number % z) * z


def rearrange_sorted_array_in_place(arr):
    arr_max = arr[-1]
    z = ((arr_max // 10) + 1) * 10  # // return integer quotient
    i, j = 0, len(arr) - 1
    for k in range(0, len(arr)):
        if k & 1:
            # one of min number should come here
            store_two_numbers_in_one_index(arr, k, arr[i], z)
            i += 1
        else:
            # one of max numbers should come here
            store_two_numbers_in_one_index(arr, k, arr[j], z)
            j -= 1
    for k in range(0, len(arr)):
        arr[k] //= z


tc = int(input())
while tc:
    n = int(input())
    # below line gives MemoryError
    # arr = list(map(int, input().split()))
    arr = list(input().split())
    for i in range(0, n):
        arr[i] = int(arr[i])

    rearrange_sorted_array_in_place(arr)
    print(*arr)
    tc -= 1
