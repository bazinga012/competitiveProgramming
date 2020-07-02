# https://leetcode.com/problems/longest-palindromic-subsequence/
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        if n == 1:
            return 1
        dp = [n*[0] for i in range(n)]
        for l in range(1, n+1):
            for i in range(0, n-l+1):
                j = i+l-1
                if i == j:
                    dp[i][j] = 1
                    continue
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1]+2
                else:
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j])
        return dp[0][n-1]

        # create sequence
        # seq = []
        # i, j = 0, n-1
        # while i<n and j>=i:
        #     if s[i] == s[j]:
        #         seq.append(s[i])
        #         i +=1
        #         j-=1
        #     elif dp[i][j] == dp[i+1][j]:
        #         i+=1
        #     else:
        #         j-=1
        # return ''.join(reversed(seq))
