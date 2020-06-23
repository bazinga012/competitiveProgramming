# https://leetcode.com/problems/queue-reconstruction-by-height/
import bisect


class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda p: p[0])
        n = len(people)
        result = n * [None]
        i = 0
        while i < n:
            fill_idx = people[i][1]
            for k in range(n):
                if fill_idx == 0 and result[k] == None:
                    result[k] = people[i]
                    break
                if fill_idx > 0 and (result[k] == None or result[k][0] >= people[i][0]):
                    fill_idx -= 1
            i += 1
        return result
