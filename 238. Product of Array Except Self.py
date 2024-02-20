"""
没啥思路 确实可以全乘起来然后一个个除 但是不让
感觉是拆成质数的乘积 然后先算正负 在去除本身的质数 但是不能用除啊 怎么算质数出来呢
30内的质数: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29

最简单就是循环算前后 时间是o(n2) 保存中间结果呢 空间需要两个数组 o(2n)的空间复杂度 时间o(n)
"""
from typing import List


class Solution:
    """
    无敌的思路 双指针+前缀和+后缀和
    太难想了 这种方式相当于避免了两个数组的中间结果
    想到了前缀和 但真没想到这种方式去算前后乘积
    """
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        preSum, afterSum = 1, 1
        pre, after = 0, len(nums) - 1
        
        res = [1] * len(nums)
        while pre < len(nums):
            res[pre] *= preSum
            res[after] *= afterSum

            afterSum *= nums[after]
            preSum *= nums[pre]

            pre += 1
            after -= 1
        
        return res
    

ss = Solution()
print(ss.productExceptSelf([1,2,3,4]))