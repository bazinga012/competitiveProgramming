# https://leetcode.com/problems/median-of-two-sorted-arrays/
import math

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n = len(nums1)
        m = len(nums2)
        
        if n == 0:
            return nums2[m//2] if m & 1 else (nums2[m//2] + nums2[(m//2)-1])/2
        if m == 0:
            return nums1[n//2] if n & 1 else (nums1[n//2] + nums1[(n//2)-1])/2
        
        if n >= m:
            smaller, bigger = nums2, nums1
        else:
            smaller, bigger = nums1, nums2
            n, m = m, n

        i_min, i_max = -1, m-1 # index when we don't take anything from smaller array(i_min) or take everything(i_max)
        needed = (n+m+1)//2 # how many elements we need to take till lower median
        is_odd = (n+m) & 1 == 1
        while i_min <= i_max:
            i = (i_min + i_max)//2
            j = needed - (i+1) - 1

            x = smaller[i] if i >= 0 else None
            y = bigger[j] if j >= 0 else None

            x_next = smaller[i+1] if i < m-1 else None
            y_next = bigger[j+1] if j < n-1 else None

            if x_next != None and y != None and x_next < y:
                i_min = i+1
            elif y_next != None and x != None and y_next < x:
                i_max = i - 1
            else:
                if is_odd:
                    if x != None and y != None:
                        return max(x, y)
                    if x == None:
                        return min(y, x_next)
                    if y == None:
                        return min(x, y_next)
                else:
                    x_next = math.inf if x_next == None else x_next
                    y_next = math.inf if y_next == None else y_next
                    x = -math.inf if x == None else x
                    y = -math.inf if y == None else y
                    return (min(x_next, y_next) + max(x, y))/2
        return None
