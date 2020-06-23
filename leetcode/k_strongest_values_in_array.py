# https://leetcode.com/problems/the-k-strongest-values-in-an-array/
class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        n = len(arr)
        m = arr[(n-1)//2]
        t, i, j = 0, 0, n-1
        sol = []
        while len(sol) < k:
            if i == j:
                sol.append(arr[i])
                break
            a = abs(arr[i]-m)
            b = abs(arr[j] - m)
            if a > b:
                sol.append(arr[i])
                i += 1
            elif a < b:
                sol.append(arr[j])
                j -= 1
            else:
                p = max(arr[i], arr[j])
                if arr[i] == p:
                    sol.append(arr[i])
                    i += 1
                elif arr[j] == p:
                    sol.append(arr[j])
                    j -= 1
                else:
                    break
        return sol
