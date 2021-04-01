class Solution:

    def clumsy(self, N: int) -> int:
        '''
        直接解法
        '''
        nums = []
        while N > 0:
            res, N = N, N - 1
            if N > 0:
                res, N = res * N, N - 1
            if N > 0:
                res, N = res // N, N - 1
            nums.append(-res)
            if N > 0:
                nums.append(N)
                N -= 1
        nums[0] = -nums[0]
        return sum(nums)

    def clumsy_(self, N: int) -> int:
        '''
        栈模拟
        python // 正数负数取值有坑
        '''
        nums = [N]
        N -= 1
        index = 0
        while N > 0:
            if index % 4 == 0:
                nums.append(nums.pop() * N)
            elif index % 4 == 1:
                if nums[-1] >= 0:
                    nums.append(nums.pop() // N)
                else:
                    nums.append(-((-nums.pop()) // N))
            elif index % 4 == 2:
                nums.append(N)
            else:
                nums.append(-N)
            index += 1
            N -= 1
        return sum(nums)