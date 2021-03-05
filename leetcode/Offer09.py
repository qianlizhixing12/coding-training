class CQueue:

    def __init__(self):
        self.data = []

    def appendTail(self, value: int) -> None:
        self.data.append(value)

    def deleteHead(self) -> int:
        return self.data.pop(0) if len(self.data) > 0 else -1


# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()