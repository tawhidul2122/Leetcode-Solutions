// https://leetcode.com/problems/contains-duplicate-ii

class Solution:
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """

        # approach: use a hash map to save index of each value and
        #           then check if index of the closest same value is <= k

        index_map = {}

        for i in range(len(nums)):
            num = nums[i]
            if num in index_map and i - index_map[num] <= k:
                return True
            index_map[num] = i

        return False