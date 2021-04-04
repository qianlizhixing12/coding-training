import random


def solution(f):
    '''
    :param f: 随机函数，50%概率返回0，50%概率返回1
    :return fun: 返回函数，同等概率随机返回0-7
    '''

    def fun():
        '''
        运用位运算，调用三次f函数
        '''
        ans = 0
        for _ in range(3):
            ans = (ans << 1) + f()
        return ans

    return fun


def f():
    '''
    同等概率返回0，1
    '''
    return random.choices([0, 1], [0.5, 0.5])[0]


if __name__ == "__main__":
    fun = solution(f)
    print([fun() for _ in range(8)])