import math
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m= len(dungeon)
        if m==0: 
            return 1
        n = len(dungeon[0])
        dp = [[None]*n for i in range(m)]
        dp[m-1][n-1] = 1 if dungeon[m-1][n-1] >= 1 else 1 - dungeon[m-1][n-1]
        print(dp)
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if i+1 <= m-1:
                    if dungeon[i][j] >= dp[i+1][j]:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = dp[i+1][j] - dungeon[i][j]
                if j+1 <= n-1:
                    if dungeon[i][j] >= dp[i][j+1]:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = min(dp[i][j] or math.inf, dp[i][j+1] - dungeon[i][j])
        print(dp)
        return dp[0][0]