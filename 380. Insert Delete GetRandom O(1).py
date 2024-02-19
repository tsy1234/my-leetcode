# 不喜欢写这种东西 数据结构的应用 抄下答案
from random import choice


class RandomizedSet:
    
    """
    用数组去保证random的o(1)和平均概率 insert和remove也可以做到o(1)
    用map去判断是否存在
    """
    def __init__(self):
        self.nums = []
        self.kv = {}

    def insert(self, val: int) -> bool:
        if val in self.kv:
            return False
        self.nums.append(val)
        self.kv[val] = len(self.nums) - 1
        return True

    """
    这里有个巧妙的 利用最后一个去填充删除的那个 然后pop掉 保证下标一致性
    """
    def remove(self, val: int) -> bool:
        if val not in self.kv:
            return False
        
        self.nums[self.kv[val]] = self.nums[-1]
        self.kv[self.nums[-1]] = self.kv[val]
        self.nums.pop()
        del self.kv[val]
        
        return True

    def getRandom(self) -> int:
        return choice(self.nums)
