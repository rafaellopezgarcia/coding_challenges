from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        new_intervals = [intervals[0]]
        for interval in intervals:
            if new_intervals[-1][1] >= interval[0]:
                if interval[1] > new_intervals[-1][1]:
                    new_intervals[-1][1] = interval[1]
            else:
                new_intervals.append(interval)
        return new_intervals
