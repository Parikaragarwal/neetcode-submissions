class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        chars: List[str] = list(strs[0])
        if len(chars) == 0:
            return ""

        for i in range(1, len(strs)):
            end: int = min(len(chars), len(strs[i]))
            j: int = 0
            while j < end and chars[j] == strs[i][j]:
                j += 1

            chars = chars[:j]
        return "".join(chars)
