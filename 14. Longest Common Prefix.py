"""
应该一次循环就可以 但是想了下 居然不知道怎么写。。
先来个暴力试探下
"""
from typing import List

class Solution:
    """
    violence
    感觉写的不好 应该又更简洁的暴力写法 时间复杂度O(mxn)
    """
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ''
        start = 0
        while True:
            if len(strs[0]) <= start:
                break

            match = True
            match_char = strs[0][start]
            for idx in range(1, len(strs)):
                if start >= len(strs[idx]) or strs[idx][start] != match_char:
                    match = False
                    break
            
            if not match:
                break

            res += match_char
            start += 1
        
        return res
    
    """
    牛逼的来了 先排序 然后比较第一个和最后一个的前面相同的 太厉害了
    时间复杂度O(mlogm + n)
    """
    def sort_and_compare(self, strs: List[str]):

        strs.sort()
        
        min_len = min(len(strs[0]), len(strs[-1]))
        res = ''
        for idx in range(min_len):
            if strs[0][idx] != strs[-1][idx]:
                return res
            res += strs[0][idx]
        
        return res
        

ss = Solution()
print(ss.longestCommonPrefix(["flower","flow","flight"]))