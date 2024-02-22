"""
找规律的感觉哦
n行的话 有点想不出来 最简单的肯定是模拟构建数组 然后按顺序去拼接就行
但肯定又O(1)空间复杂度的方法
画了ixa n行的话 就是2n-2 然后每行的下一个如果是斜的路上的 就是隔着2n-2-(idx*2)
如果是竖着下去的那个 就是idx*2 然后一次分层遍历就可以 时间复杂度是O(m)
"""
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        
        # 边界处理 大于的和只有一行的
        if numRows >= len(s) or numRows == 1: 
            return s

        res = ''
        for row in range(numRows):
            idx = row
            is_zig = False
            
            while idx < len(s):
                res += s[idx]
                if (row == 0 or row == (numRows - 1)):
                    step = 2 * numRows - 2
                elif is_zig:
                    step = (row * 2)
                else:
                    step = (2 * numRows - 2) - (row * 2)

                idx += step
                is_zig = not is_zig

        return res
    
    """
    这巨扯 无敌的脑子
    思路很简单 第一层往下面的层 最后一层往上面的层 用一个flag来做层数增减 无敌!
    """
    def best(self, s: str, numRows: int):
        if numRows < 2: return s
        res = ["" for _ in range(numRows)]
        i, flag = 0, -1
        for c in s:
            res[i] += c
            if i == 0 or i == numRows - 1: flag = -flag
            i += flag
        return "".join(res)
    
ss = Solution()
print(ss.convert("AB", 1))