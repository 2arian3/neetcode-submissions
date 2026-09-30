class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int minHeight = INT_MAX;
        unordered_map<int, vector<int>> heightMap;
        unordered_map<int, vector<int>> adjs;

        for (const auto& e: edges) {
            adjs[e[0]].push_back(e[1]);
            adjs[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++) {
            int height = dfs(adjs, i, -1);
            minHeight = min(minHeight, height);
            heightMap[height].push_back(i);
        }

        return heightMap[minHeight];
    }

    int dfs(unordered_map<int, vector<int>>& adjs, int node, int parent) {
        int height = 0;

        for (const auto& nei: adjs[node]) {
            if (nei == parent)
                continue;
            
            height = max(dfs(adjs, nei, node), height);
        }

        return height + 1;
    }
};