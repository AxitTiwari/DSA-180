## https://leetcode.com/problems/find-the-duplicate-number/submissions/1941013855

from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        
        ## this question is not of a array question instead it is a linked list, cycle detection question
        slow, fast = 0, 0
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                break
            
        slow2 = 0
        while True:
            slow = nums[slow]
            slow2 = nums[slow2]
            if slow == slow2:
                return slow