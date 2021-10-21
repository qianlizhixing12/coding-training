from collections import defaultdict


class Solution:

    def isNumber(self, s: str) -> bool:
        # 空字符串
        if s == "":
            return False

        # 单字符串处理
        if len(s) == 1:
            return s.isdigit()

        # 下列逻辑在len(s) >= 2
        # 记录符号出现位置数组，记录数字个数
        node = defaultdict(list)
        for i, c in enumerate(s):
            # 数字统一统计
            if c.isdigit():
                node["d"].append(i)
                continue
            # 统计+ - . E(e)
            if c == "+" or c == "-" or c == "." or c.upper() == "E":
                node[c.upper()].append(i)
            # 其他字符
            else:
                return False

        # 对数字处理
        if len(node["d"]) == 0:
            return False

        # 对 . 处理
        if len(node["."]) > 1:
            return False

        # 对 E 处理
        if len(node["E"]) > 1:
            return False
        if len(node["E"]) == 1:
            # E个数为1
            # E不能出现在首尾
            if node["E"][0] == 0 or node["E"][0] == len(s) - 1:
                return False
            # E后面必须是数字
            # if not s[node["E"][0] + 1].isdigit():
            #     return False
            # E前面必须是.时，.前面必须有数字
            if len(node["."]) == 1:
                if node["."][0] > node["E"][0]:
                    return False
                if node["E"][0] - 1 == node["."][0] and node["d"][0] > node["."][0]:
                    return False
            # E前面必须是数字
            elif not s[node["E"][0] - 1].isdigit():
                return False

        # 对 + - 处理
        if len(node["+"]) + len(node["-"]) > 2:
            return False
        if len(node["+"]) + len(node["-"]) == 2:
            if len(node["E"]) != 1:
                return False
            tmp = sorted(node["+"] + node["-"])
            # 两个正负，一个在首，一个在E后
            if tmp[0] != 0:
                return False
            if tmp[1] != node["E"][0] + 1:
                return False
            # 不能出现在尾部
            if tmp[1] != len(s) - 1:
                return False
        if len(node["+"]) + len(node["-"]) == 1:
            tmp = node["+"] + node["-"]
            # if
            if tmp[0] != 0:
                return False

        return True


# print(Solution().isNumber("6e6.5") == False)
# print(Solution().isNumber(".0e7") == True)
# print(Solution().isNumber("46.e3") == True)
print(Solution().isNumber("005047e+6") == True)