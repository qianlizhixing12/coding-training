class Solution:

    def calculate1(self, s: str) -> int:
        '''
        第一版
        '''
        nums = []
        ops = []

        n = len(s)
        i = 0
        while i < n:
            c = s[i]
            if c.isdigit():
                num = 0
                while i < n and s[i].isdigit():
                    num = num * 10 + int(s[i])
                    i += 1
                if len(ops) != 0 and (ops[-1] == '*' or ops[-1] == '/'):
                    val = nums.pop()
                    op = ops.pop()
                    if op == '*':
                        num *= val
                    elif op == '/':
                        num = val // num
                nums.append(num)
            elif c == '+' or c == '-' or c == '*' or c == '/':
                ops.append(c)
                i += 1
            else:
                i += 1

        res = nums.pop(0)
        while len(ops):
            op = ops.pop(0)
            if op == '+':
                res += nums.pop(0)
            if op == '-':
                res -= nums.pop(0)
        return res

    def calculate2(self, s: str) -> int:
        '''
        第一版优化，还是两个栈·
        '''
        nums = []
        ops = []
        n = len(s)
        num = 0
        for i, c in enumerate(s):
            if c.isdigit():
                num = num * 10 + int(c)
            if i == n - 1 or c == '+' or c == '-' or c == '*' or c == '/':
                if len(ops) != 0 and (ops[-1] == '*' or ops[-1] == '/'):
                    op = ops.pop()
                    if op == '*':
                        nums[-1] *= num
                    elif op == '/':
                        nums[-1] //= num
                else:
                    nums.append(num)
                ops.append(c)
                num = 0

        res = nums.pop(0)
        for i in range(len(nums)):
            op = ops[i]
            if op == '+':
                res += nums[i]
            if op == '-':
                res -= nums[i]
        return res

    def calculate3(self, s: str) -> int:
        '''
        优化，一个栈，用正负数表示前面的正负号
        '''
        nums = []
        n = len(s)
        op = '+'
        num = 0
        for i, c in enumerate(s):
            if c.isdigit():
                num = num * 10 + int(c)
            if i == n - 1 or c == '+' or c == '-' or c == '*' or c == '/':
                if op == '*':
                    nums[-1] *= num
                elif op == '/':
                    if nums[-1] >= 0:
                        nums[-1] = nums[-1] // num
                    else:
                        nums[-1] = abs(nums[-1]) // num * -1
                elif op == '+':
                    nums.append(num)
                elif op == '-':
                    nums.append(-num)
                op = c
                num = 0
        return sum(nums)