from typing import List


class Solution:
    def getWays(self, amount, coins):
        if amount == 0:
            return 1
        if amount in self.dp:
            return self.dp[amount]
        self.dp[amount] = 0
        for coin in coins:
            remaining_amount = amount - coin
            if remaining_amount < 0:
                break
            elif remaining_amount == 0:
                self.dp[amount] += 1
            else:
                r_ways = self.getWays(remaining_amount, coins)
                self.dp[amount] += r_ways
        return self.dp[amount]

    def change(self, amount: int, coins: List[int]) -> int:
        self.dp = {}
        return self.getWays(amount, coins)

if __name__ == '__main__':
  print(Solution().change(5, [1, 2, 5]))