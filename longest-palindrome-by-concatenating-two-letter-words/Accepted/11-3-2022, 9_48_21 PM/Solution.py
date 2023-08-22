// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        ans = 0
        seen = collections.defaultdict(int)
        for word in words:
            if seen[word] > 0:
                ans += 4
                seen[word] -= 1
            else:
                seen[word[::-1]] += 1
        for word in seen:
            if seen[word] > 0 and word[0] == word[1]:
                ans += 2
                break
        return ans