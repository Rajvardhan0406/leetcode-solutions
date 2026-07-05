import heapq

class Solution:
    def totalCost(self, costs, k, candidates):
        n = len(costs)
        lo, hi = 0, n - 1
        left, right = [], []

        for _ in range(candidates):
            if lo <= hi:
                heapq.heappush(left, (costs[lo], lo))
                lo += 1

        for _ in range(candidates):
            if lo <= hi:
                heapq.heappush(right, (costs[hi], hi))
                hi -= 1

        total = 0
        for _ in range(k):
            if not right or (left and left[0] <= right[0]):
                cost, idx = heapq.heappop(left)
                total += cost
                if lo <= hi:
                    heapq.heappush(left, (costs[lo], lo))
                    lo += 1
            else:
                cost, idx = heapq.heappop(right)
                total += cost
                if lo <= hi:
                    heapq.heappush(right, (costs[hi], hi))
                    hi -= 1

        return total