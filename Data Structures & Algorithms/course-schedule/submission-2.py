class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjs = {i: [] for i in range(numCourses)}

        for course, pre in prerequisites:
            adjs[course].append(pre)

        visiting = [0] * numCourses
        
        def dfs(course: int):
            if visiting[course] == 1:
                return False

            if visiting[course] == 2:
                return True

            visiting[course] = 1
            for pre in adjs[course]:
                if not dfs(pre):
                    return False

            visiting[course] = 2
            return True



        for i in range(numCourses):
            if not dfs(i):
                return False
        
        return True