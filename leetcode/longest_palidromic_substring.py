# https://leetcode.com/problems/longest-palindromic-substring/
class Solution:
    def __init__(self):
        self.dp = []

    def expand_from_center(self, s, l, h):
        n = len(s)
        while l >= 0 and h < n and s[l] == s[h]:
            l -= 1
            h += 1
        # since now s[l] and s[h] dont match and we have decremented and incremented them in above loop
        return (h-1) - (l+1) + 1  # h-l-1

    def longestPalindrome(self, s: str) -> str:
        # n^2 time o(1) space
        l, h = 0, 0
        for i in range(0, len(s)-1):
            l_odd = self.expand_from_center(s, i, i)
            l_even = self.expand_from_center(s, i, i+1)
            max_with_i_center_even_or_odd = max(l_odd, l_even)
            if max_with_i_center_even_or_odd > (h-l+1):
                # if greater than current max_len which is h-l+1 update h and l
                # racecar let say i=3 s[i] = e max_with_i_center_even_or_odd=7 which is odd
                # aabbaa  let say i=2 s[i] = b s[i+1] = b max_with_i_center_even_or_odd=6 which is even
                # minus in l since i is towards left
                # -1 handles even and odd value of max_with_i_center_even_or_odd
                l = i-((max_with_i_center_even_or_odd-1)//2)
                h = i+(max_with_i_center_even_or_odd//2)
        return s[l:h+1]

