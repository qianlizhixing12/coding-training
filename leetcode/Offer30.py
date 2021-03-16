class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = [float('inf')]
        self.min_data = [float('inf')]

    def push(self, x: int) -> None:
        self.data.append(x)
        self.min_data.append(min(x, self.min_data[-1]))

    def pop(self) -> None:
        self.data.pop()
        self.min_data.pop()

    def top(self) -> int:
        return self.data[-1]

    def min(self) -> int:
        return self.min_data[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()