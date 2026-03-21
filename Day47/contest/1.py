class Solution:
    def trimTrailingVowels(self, s: str) -> str:
        def isVowel(ch):
            vowels = ["a", "e", "i", "o", "u"]
            return True if ch in vowels else False

        trimedS = ""
        i = len(s) - 1  
        
        while i >= 0 and isVowel(s[i]):
            i -= 1
        
        return s[:i+1]