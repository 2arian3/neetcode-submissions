class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        res = [False for _ in range(len(queries))]

        adjs = defaultdict(list)
        for c1, c2 in prerequisites:
            adjs[c1].append(c2)

        def dfs(start, end, visited):
            if start == end:
                return True
            
            visited.add(start)
            for c in adjs[start]:
                if c not in visited:
                    if dfs(c, end, visited):
                        return True
            
            return False

        for i, q in enumerate(queries):
            if dfs(q[0], q[1], set()):
                res[i] = True

        return res