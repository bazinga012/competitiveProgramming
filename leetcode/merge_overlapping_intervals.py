class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda i: i[0])
        n = len(intervals)
        if n <= 1:
            return intervals
        response = []
        i = 0
        j = i+1
        while j < n:
            if intervals[i][1] >= intervals[j][0]:
                intervals[i][1] = max(intervals[j][1], intervals[i][1])
            else:
                response.append(intervals[i])
                i = j
            j += 1
        response.append(intervals[i])
        return response
