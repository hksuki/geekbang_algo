class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def generate(i, s):
            if i == len(digits):
                return ret.append(s)
            for item in map_list[digits[i]]:
                generate(i + 1, s + item)
            return

        if len(digits) == 0:
            return []
        map_list = {
            "2": "abc", "3": "def", "4": "ghi", "5": "jkl",
            "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"
        }
        ret = []
        generate(0, "")

        return ret[:]