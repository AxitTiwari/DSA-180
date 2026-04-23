from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        
        if len(p) > len(s): return []

        ## hashmaps for p string and s string
        p_count, s_count = {}, {}

        ## fill the window of p, and s upto first len(p) elements
        for i in range(len(p)):
            p_count[p[i]] = 1 + p_count.get(p[i], 0)
            s_count[s[i]] = 1 + s_count.get(s[i], 0)

        ## start appening index in list, if both window matches
        res = [0] if p_count == s_count else []
        l = 0

        for r in range(len(p), len(s)):
            ## put the right value in s window
            s_count[s[r]] = 1 + s_count.get(s[r], 0)

            ## remove the left value
            s_count[s[l]] -= 1

            ## if 0 after removal, then delete element
            if s_count[s[l]] == 0:
                s_count.pop(s[l])

            ## go left
            l += 1

            ## if both window matches, append in answer
            if s_count == p_count:
                res.append(l)
        return res
        