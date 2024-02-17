from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        return self.dp_v2(nums)
    
    # 耗时太大了 超时
    def rec(self, pos: int, nums: List[int]) -> bool:
        print(pos)
        if pos == len(nums) - 1:
            return True
        if (pos >= len(nums)) or (nums[pos] == 0):
            return False
        
        for step in range(1, nums[pos] + 1):
            if self.rec(pos + step, nums):
                return True
        
        return False
    
    # dp应该也可以 方程如下:
    # dp[i]代表i是否可以到达
    # if dp[j] + nums[j] >= i then dp[i] = true
    # dp的核心就是两个 1.初始化 2.动态规划方程推演和实现
    # 这个超时了 两次循环很费时 n平方
    def dp(self, nums: List[int]):
        dp = [False] * len(nums)
        dp[0] = True
        
        for idx in range(1, len(nums)):
            for pre in range(idx):
                if pre + nums[pre] >= idx:
                    dp[idx] = True
                    break
            if dp[idx] is not True:
                return False
        
        return True if dp[len(nums) - 1] else False
    
    
    # 优化下
    # dp定义：dp[i]代表从0出发 经过j<=i 可以到的地方
    # if dp[i - 1] >= i then dp[i] = max(dp[i-1], dp[i] + nums[i])
    # else dp[i] = dp[i - 1]
    def dp_v2(self, nums: List[int]):
        # 初始化dp数组
        dp = [0 for _ in range(len(nums))]
        dp[0] = nums[0]

        for idx in range(1, len(nums)):
            dp[idx] = max(dp[idx - 1], idx + nums[idx]) if dp[idx - 1] >= idx else dp[idx - 1]
        
        return dp[len(nums) - 1] >= (len(nums) - 1)
    
    # 贪心也是博大精深啊
    # 继续优化 会发现dp方程里idx只和idx-1有关 这样的话可以把dp数组干掉 最后就变成了贪心
    def greed(self, nums: List[int]):
        maxn = 0
        for idx in range(0, len(nums)):
            if idx > maxn:
                return False
            maxn = max(maxn, idx + nums[idx])
        return True if maxn >= len(nums) - 1 else False

a = [2,3,1,1,4]
ss = Solution()
print(ss.canJump(a))