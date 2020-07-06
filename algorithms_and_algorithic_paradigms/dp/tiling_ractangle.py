import math
dp = {"1-1": 1}
class Solution:
    # wrong answer
    def tilingRectangle(self, n: int, m: int) -> int:
        global dp
        if n==1: return m
        if m==1: return n
        key = f"{n}-{m}"
        rev_key = f"{m}-{n}"
        if key in dp:
            print(f"{key}: {dp[key]}")
            return dp[key]
        if rev_key in dp:
            print(f"{rev_key}: {dp[rev_key]}")
            return dp[rev_key]
        if n == m:
            dp[key] = 1
            return dp[key]
        mi = min(n, m)
        g_min = math.inf
        for i in range(1, mi+1):
            if m-i == 0:
                a = self.tilingRectangle(n-i, i) + 1
                b = self.tilingRectangle(n-i, m) + 1
            elif n-i == 0:
                a = self.tilingRectangle(n, m-i) + 1
                b = self.tilingRectangle(i, m-i) + 1
            else:
                a = self.tilingRectangle(n, m-i) + self.tilingRectangle(n-i, i) + 1
                b = self.tilingRectangle(n-i, m) + self.tilingRectangle(i, m-i) + 1
            g_min = min(a, b , g_min)
        dp[f"{n}-{m}"] = g_min
        print(f"{key}: {dp[key]}")
        return g_min


if __file__ == '__main__':
    Solution().tilingRectangle(11,13)