class Solution:
    def threeSum(self, nums):
        """three sum question solved by double pointer

        Args:
            nums (List[int]): input array

        Returns:
            List[List[int]]: result list
        """
        ret = []
        if nums is None or len(nums) < 3:
            return ret[:]
        nums.sort()
        i = 0
        while i < len(nums) - 2:
            L = i + 1
            R = len(nums) - 1
            if nums[i] > 0:
                break
            while L < R:
                if nums[i] + nums[L] + nums[R] < 0:
                    L += 1
                elif nums[i] + nums[L] +nums[R] > 0:
                    R -= 1
                else:
                    while nums[L] == nums[L+1] and L + 1 < R: L += 1
                    while nums[R] == nums[R-1] and L < R - 1: R -= 1
                    ret.append([nums[i], nums[L], nums[R]])
                    L += 1
                    R -= 1
            while nums[i] == nums[i+1] and i < len(nums) - 2: i += 1
            i += 1
        return ret[:]

class MySolution:
    def twoSum(self, nums, source_index, target):
        i = 0
        cache = {}
        ret = []
        while i < len(nums):
            if i == source_index:
                i += 1
                continue
            if cache.get(nums[i], False):
                tmp = sorted([nums[i], target-nums[i], nums[source_index]])
                if tmp in ret:
                    i += 1
                    continue
                else:
                    ret.append(tmp)
            else:
                cache[target-nums[i]] = True
            i += 1
        return ret[:]

    def threeSum(self, nums):
        ret = []
        i = 0
        while i < len(nums):
            tmp_ret = self.twoSum(nums, i, 0 - nums[i])
            for tmp in tmp_ret:
                if tmp not in ret:
                    ret.append(tmp)
            i += 1
        return ret[:]