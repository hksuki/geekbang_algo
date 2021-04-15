class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def DFS(start, path):
            # terminator start == n len(path) == k
            if len(path) + (n - start) < k:
                return
            if len(path) == k:
                ret.append(path[:])
                return
            for item in range(n)[start:]:
                path.append(item + 1)
                DFS(item + 1, path)
                path.remove(item + 1)
            return

        ret, path = [], []
        DFS(0, path)
        return ret[:]