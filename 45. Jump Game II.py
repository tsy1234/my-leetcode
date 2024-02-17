from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        return self.dp_v3(nums)
    
    # 这总和贪心没关系吧 求最小 绝对是dp
    # dp定义:
    # dp[i]代表从0到i的位置需要跳几次
    # 动态规划方程：
    # dp[i] = min(dp[j] + 1, dp[i]) if j + nums[j] >= i
    # 两次循环 不知道能不能优化 明天写吧
    # 虽然过了 但是有几个case耗时好长
    def dp(self, nums: List[int]) -> int:
        # 定义
        dp = [float('inf')] * len(nums)
        dp[0] = 0

        # 迭代计算
        for last in range(1, len(nums)):
            for pre in range(last):
                if pre + nums[pre] >= last:
                    dp[last] = min(dp[last], dp[pre] + 1)
        
        return dp[-1]

    # 简单优化下 第二次循环反着来看看 但是感觉差不多的样子
    # 确实快了蛮多 第二次循环往后走避免了不需要计算的部分 因为往后知道最多能到哪里 
    def dp_v2(self, nums: List[int]):
        # 定义
        dp = [float('inf')] * len(nums)
        dp[0] = 0

        # 迭代计算
        for pre in range(0, len(nums)):
            for last in range(pre + 1, min(pre + nums[pre] + 1, len(nums))):
                    dp[last] = min(dp[last], dp[pre] + 1)
        
        return dp[-1]
    
    # 绝对还能优化 一次循环试试
    # 看了下答案 就是找最远的那个可以到i的j去+1 最远的那个肯定是step最小的 省略掉中间那些无用的j的计算
    # 找j的过程用了双指针 很巧妙 避免了内部的第二次循环
    # 这次巨快 速度超越91% 内存超越61%
    # 感觉还能优化 因为迭代方程也只和最远的那个有关系 不需要数组来存储所有的
    def dp_v3(self, nums: List[int]):
        # 定义
        dp = [float('inf')] * len(nums)
        dp[0] = 0

        # 迭代计算
        point = 0
        for cur in range(1, len(nums)):
            # 指针找最远的
            while point + nums[point] < cur: 
                point += 1
            
            dp[cur] = dp[point] + 1

        return dp[-1]
    
    # 空间还能优化 明天写 其实就是贪心了 贪心是不是都可以从动态规划的思路去解释呢
    def dp_v4(self, nums: List[int]):
        pass

ss = Solution()
res = ss.jump([2,3,1,1,4])
print(res)