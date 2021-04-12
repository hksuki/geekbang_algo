class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ret = collections.defaultdict(list)
        for st in strs:
            key = "".join(sorted(st))
            ret[key].append(st)
        return list(ret.values())