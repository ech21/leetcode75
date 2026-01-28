class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        shorter = min(len(word1), len(word2))
        result = ""
        for i in range(shorter):
            result += word1[i]
            result += word2[i]
        if len(word1) > len(word2):
            result += word1[shorter:]
        else:
            result += word2[shorter:]
        return result

# This is slow because python strings are immutable.
# Each concatenation creates a new string, leading to O(n^2) time complexity.
# Space complexity is O(n + m) where n and m are lengths of word1 and word2 respectively.
# no auxiliary space is taken, so it's O(1)
# A more efficient approach would be to use a list to collect characters and join them at the end.class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        shorter = min(len(word1), len(word2))
        result = []
        for i in range(shorter):
            result.append(word1[i])
            result.append(word2[i])
        if len(word1) > len(word2):
            result.append(word1[shorter:])
        else:
            result.append(word2[shorter:])
        return "".join(result)