"""
简单题和hard题都不想做啊
"""
class Solution:

    def __init__(self):
        self.kv = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        
    """
    从前往后处理呗 逐个加起来 要特殊处理I,X,C的6中减法情况 最多两位
    但还是有些小trick的啊 牛逼
    这种从前往后处理减法 确实有点麻烦 从后往前确实更好点
    """
    def romanToInt(self, s: str) -> int:
        total = 0
        pre_num = 0

        for idx in range(1, len(s)):
            pre_num = self.kv[s[idx - 1]]
            now_num = self.kv[s[idx]]

            if pre_num < now_num:
                total -= pre_num
            else:
                total += pre_num
        
        total += self.kv[s[-1]]

        return total
    
    def romanToIntBack(self, s: str):
        total = 0
        
        
    
ss = Solution()
print(ss.romanToInt('MCMXCIV'))

            