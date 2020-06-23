# https://leetcode.com/problems/shuffle-the-array/
class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        i, j = 0, n
        k = 0
        z = max(nums)*10
        for k in range(0, 2*n):
            if k & 1:
                nums[k] += ((nums[j] % z)*z)
                j += 1
            else:
                nums[k] += ((nums[i] % z)*z)
                i += 1
        for k in range(0, 2*n):
            nums[k] //= z
        return nums