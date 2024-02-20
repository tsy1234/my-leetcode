"""
题目挺简单 其实只要gas的总和小于cost的总和 就一定不能循环
然后就是怎么去找最好的开始位置的问题了
加的油用贪心 每次都全加就行 暴力的话就是o(n2)的时间复杂度 o(1)的空间复杂度
更简单的感觉想不出来 好像没符合啥模式 bfs也是o(n2)的样子
前缀和？也不像 没固定开始位置
"""
from typing import List


class Solution:
    
    """
    先来个暴力 最后几个超时了 没啥问题
    """
    def violence(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1
        
        for start in range(len(gas)):
            remain_gas = 0
            can_arrive = True
            for idx in range(start, len(gas)):
                # 跳到下一步还剩下的汽油
                remain_gas += (gas[idx] - cost[idx])
                if remain_gas < 0:
                    can_arrive = False
                    break
            
            if can_arrive is not True:
                continue

            for idx in range(start):
                remain_gas += (gas[idx] - cost[idx])
                if remain_gas < 0:
                    can_arrive = False
                    break
            
            if can_arrive is not True:
                continue
            else:
                return start
        
        return -1
    
    """
    感觉是贪心哎 找每次能剩下最多的那个
    晕了 看答案有点像数学问题 最小前缀和的下一个 麻了
    利用题目里只有一个解的描述 其实就是贪心 我也想到了 但是不知道怎么去贪心 没想到结合前缀和
    这样就是一次循环
    """
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        minn = 0 # 这里初始为0就行 因为一定有小于0的 
        minn_pos = -1

        pre_remain = 0

        for idx in range(len(gas)):
            pre_remain += (gas[idx] - cost[idx])

            if pre_remain < minn:
                minn = pre_remain
                minn_pos = idx
            
        if pre_remain < 0: # 必没有
            return -1
        
        return (minn_pos + 1) % len(gas)

ss = Solution()
print(ss.canCompleteCircuit([1,2,3,4,5], [3,4,5,1,2]))