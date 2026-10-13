class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        dist = {i: float('inf') for i in range(1, n + 1)}

        adjs = defaultdict(list)
        for v1, v2, d in times:
            adjs[v1].append((v2, d))

        def dfs(i: int, time: int):
            if time >= dist[i]:
                return
            
            dist[i] = time
            for nei, delay in adjs[i]:
                dfs(nei, delay + time)

        dfs(k, 0)
        minimumTime = max(dist.values())
        return -1 if minimumTime == float('inf') else minimumTime