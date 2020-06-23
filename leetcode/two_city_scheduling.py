# https://leetcode.com/problems/two-city-scheduling/
import math


class Solution:

    def func(self, costs, i=0, cost_A=0, cost_B=0, size_A=0, size_B=0):
        n = len(costs)
        if i == n:
            return cost_A + cost_B
        if size_A < n//2:
            a1 = self.func(costs, i+1, cost_A +
                           costs[i][0], cost_B, size_A+1, size_B)
        else:
            a1 = math.inf
        if size_B < n//2:
            a2 = self.func(costs, i+1, cost_A, cost_B +
                           costs[i][1], size_A, size_B + 1)
        else:
            a2 = math.inf
        return min(a1, a2)

    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs.sort(key=lambda cost: -abs(cost[0]-cost[1]))
        assigned_to_city_A, assigned_to_city_B = 0, 0
        n = len(costs)//2
        total_A, total_B = 0, 0
        for person, cost in enumerate(costs):
            cost_A, cost_B = cost
            if (cost_A <= cost_B and assigned_to_city_A < n) or (assigned_to_city_B == n):
                assigned_to_city_A += 1
                total_A += cost_A
            elif cost_B < cost_A and assigned_to_city_B < n or (assigned_to_city_A == n):
                assigned_to_city_B += 1
                total_B += cost_B
        return total_A + total_B
