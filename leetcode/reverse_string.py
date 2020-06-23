# https://leetcode.com/problems/reverse-string/
class Solution:

    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        l = len(s)
        p = l//2
        for i in range(p):
            s[i], s[l - 1 - i] = s[l - 1 - i], s[i]
