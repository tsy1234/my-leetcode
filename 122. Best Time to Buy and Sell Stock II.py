from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sum = 0
        if len(prices) < 2:
            return sum
        for i in range(len(prices)):
            if i == len(prices) - 1:
                break
            if prices[i + 1] - prices[i] > 0:
                sum += prices[i + 1] - prices[i]
        return sum if sum > 0 else 0
    


        