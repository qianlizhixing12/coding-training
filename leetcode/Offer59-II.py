from queue import Queue, deque


class MaxQueue1:

    def __init__(self):
        self._data = []
        self._index = -1
        self._max = deque()

    def max_value(self) -> int:
        if not self._max:
            return -1

        return self._data[self._max[0]]

    def push_back(self, value: int) -> None:
        self._data.append(value)

        while self._max and self._data[self._max[-1]] <= value:
            self._max.pop()
        self._max.append(len(self._data) - 1)

    def pop_front(self) -> int:
        if not self._max:
            return -1

        self._index += 1
        while self._max and self._max[0] <= self._index:
            self._max.popleft()

        return self._data[self._index]


class MaxQueue:

    def __init__(self):
        self._data = Queue()
        self._max = deque()

    def max_value(self) -> int:
        if not self._max:
            return -1

        return self._max[0]

    def push_back(self, value: int) -> None:
        self._data.put(value)

        while self._max and self._max[-1] < value:
            self._max.pop()
        self._max.append(value)

    def pop_front(self) -> int:
        if not self._max:
            return -1

        ans = self._data.get()
        if self._max and self._max[0] == ans:
            self._max.popleft()

        return ans
