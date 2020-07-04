import math
import bisect
from typing import List

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        if(target <= startFuel):
            return 0
        n = len(stations)
        dp = [startFuel]
        for i in range(n):
            d = stations[i][0]
            extra_dist = stations[i][1]
            idx = bisect.bisect_left(dp, d)
            d_len = len(dp)
            if idx >= d_len:
                return -1
            dp.append(dp[d_len-1] + extra_dist)
            for i in range(d_len-1, idx, -1): # tricky reverse loop
                dp[i] = max(dp[i], dp[i-1] + extra_dist)
        idx = bisect.bisect_left(dp, target)
        d_len = len(dp)
        if idx >= d_len:
            return -1
        return idx
