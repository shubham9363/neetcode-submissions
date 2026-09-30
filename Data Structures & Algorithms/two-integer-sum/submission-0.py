class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map_ = {}
        for i in range(len(nums)):
            diff = target - nums[i]

            if diff in map_:
                return [map_[diff], i]

            map_[nums[i]] = i
        return []
