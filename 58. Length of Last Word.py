"""
这什么题目啊 从最后开始循环 第一个字符到第一个空格不就行了？
要是split trim就傻逼了
"""
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        n = len(s)
        pos = n - 1

        # 找到第一个字符
        while pos >= 0 and s[pos] == ' ':
            pos -= 1
            continue
        
        num = 0
        while pos >= 0 and s[pos] != ' ':
            num += 1
            pos -= 1
        
        return num
    
ss = Solution()
print(ss.lengthOfLastWord("luffy is still joyboy"))