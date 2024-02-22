"""
感觉比那个最长前缀的简单题要简单
从后往前处理就行吧
"""
class Solution:
    def reverseWords(self, s: str) -> str:
        res, word = '', ''
        for idx in range(len(s) - 1, -1, -1):

            # 处理完一个word
            if word != '' and s[idx] == ' ':
                if res != '':
                    res += ' '
                    
                res += word
                word = ''
            
            # 处理无word情况下空字符 直接跳过
            if word == '' and s[idx] == ' ':
                continue

            if s[idx] != ' ':
                word = s[idx] + word


        if word != '':
            res = res + (' ' if res != '' else '') + word

        return res
    
    """
    比较简单的写法 利用split函数的特性 然后去做::-1反转
    """
    def easy_code(self, s: str):
        words = s.split()
        words = [word for word in words if word]
        words = words[::-1]
        return ' '.join(words)

ss = Solution()
print(ss.reverseWords("the sky is blue"))
