class Solution:
    def maxArea(self, height: List[int]) -> int:
        """maxArea implemented by python3 with double pointer

        Args:
            height (List[int]): height array

        Returns:
            int: max area
        """
        i, j = 0, len(height) - 1
        max_val = 0
        while i < j:
            h = min(height[i], height[j])
            max_val = max(max_val, h * (j-i))
            while height[i] <= h and i < j:
                i += 1
            while height[j] <= h and i < j:
                j -= 1
        return max_val