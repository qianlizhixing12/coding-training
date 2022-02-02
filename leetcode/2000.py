class Solution:

    def reversePrefix(self, word: str, ch: str) -> str:
        pos = None

        for i, c in enumerate(word):
            if c == ch:
                pos = i
                break

        if pos is None:
            return word

        return word[pos::-1] + word[pos + 1:]


if __name__ == "__main__":
    print(Solution().reversePrefix("abcdefd", "d"))
