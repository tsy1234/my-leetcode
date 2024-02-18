from typing import List


class Solution:
    # 想不出好办法 先来个简单的
    # 排序后 从后往前比较即可 不行了直接返回
    # 居然也超过了74%时间和46%内存
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        maxn = 0
        for idx in range(len(citations) - 1, -1, -1):
            n = len(citations) - idx
            if citations[idx] >= n:
                maxn = n
            else:
                return maxn
            
        return maxn
    
    # 我绝对想到了二分排序 但是不知道怎么写 心里总是觉得要先排序才能二分
    # 但其实这道题不需要 符合分割点二段性其实就可以
    # 每个要先想下复杂度
    def bs(self, citations: List[int]):
        n = len(citations)
        left, right = 0, n
        
        while left < right:
            mid = (left + right + 1) >> 1
            total = sum([cnt >= mid for cnt in citations])
            if total >= mid:
                left = mid
            else:
                right = mid - 1
        
        return right

ss = Solution()
print(ss.bs([3,0,6,1,5]))
            