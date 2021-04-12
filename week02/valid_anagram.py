class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # 1.
        # if not s or not t:
        #     return False
        # if len(s) != len(t):
        #     return False
        # cache = {}
        # for i in range(len(s)):
        #     cache[s[i]] = cache.get(s[i], 0) + 1
        # for i in range(len(t)):
        #     cache[t[i]] = cache.get(t[i], 0) - 1
        # for v in cache.values():
        #     if v != 0:
        #         return False
        # return True

        # 2.
        # if "".join(sorted(s)) == "".join(sorted(t)):
        #     return True
        # else:
        #     return False

        # 3.
        if len(s) != len(t):
            return False
        table = [0 for _ in range(26)]
        for ch in s: table[ord(ch)-ord('a')] += 1
        for ch in t: 
            table[ord(ch)-ord('a')] -= 1
            if table[ord(ch)-ord('a')] < 0:
                return False
        return True