from typing import List

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        window = set()

        L = 0
        for R in range(len(nums)):

            ## if size of window exceeds
            if R - L > k:
                window.remove(nums[L])

                ## move window size
                L += 1

            ## element already present in array and abs(j - i) <= k
            if nums[R] in window:
                return True
            
            ## update window
            window.add(nums[R])
        return False

