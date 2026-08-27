class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        for (int i = 1; i <= n - 1; ++i) {
            bool updated = false;
            for (const auto& t : times) {
                int u = t[0], v = t[1], w = t[2];
                if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
            if (!updated)
                break;
        }

        int max_time = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == 1e9)
                return -1;
            max_time = max(max_time, dist[i]);
        }
        return max_time;
    }
};