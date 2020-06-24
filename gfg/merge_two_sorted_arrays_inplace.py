
def swap(arr, i,j):
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp

def merge_in_place(arr1, arr2):
    i, j = 0, 0
    l1, l2 = len(arr1), len(arr2)
    while (i+j)<l1 and j<l2:
        if arr1[i]<=arr2[j]:
            i+=1
        else:
            j+=1
    insertion_idx = l1 - j
    for k in range(0, j):
        temp = arr1[insertion_idx+k]
        arr1[insertion_idx + k] = arr2[k]
        arr2[k] = temp
    arr1 = sorted(arr1)
    arr2 = sorted(arr2)
    return arr1, arr2

tc = int(input())
while tc:
    n,m = list(map(int, input().split()))
    arr1 = list(map(int, input().split()))
    arr2  = list(map(int, input().split()))
    arr1, arr2 = merge_in_place(arr1, arr2)
    print(*arr1, *arr2)
    tc -= 1