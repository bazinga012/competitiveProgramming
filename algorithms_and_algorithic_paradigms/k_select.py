arr = [5, 4, 8, 6, 11, 7, 10, 9]


def swap(arr, i, j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp


def partition(arr, l, h):
    m = int((l + h) / 2)
    i = l - 1
    swap(arr, m, h)
    j = l
    while j < h:
        if arr[j] <= arr[h]:
            i += 1
            swap(arr, i, j)
        j += 1
    swap(arr, i + 1, h)
    return i + 1


def qsort(arr, l, h):
    if l < h:
        p = partition(arr, l, h)
        qsort(arr, l, p)
        qsort(arr, p + 1, h)


def kth_smallest(arr, l, h, k):
    if (h - l + 1) < k:
        raise Exception("Not possible")
    while l <= h:
        p = partition(arr, l, h)
        if (p == k - 1):
            return arr[p]
        if (p < k - 1):
            l = p + 1
        else:
            h = p - 1
