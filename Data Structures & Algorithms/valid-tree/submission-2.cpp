class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjs;
        unordered_set<int> visited;
        queue<pair<int, int>> q;

        for (const auto& e: edges) {
            adjs[e[0]].push_back(e[1]);
            adjs[e[1]].push_back(e[0]);
        }

        q.push({1, -1});

        while (!q.empty()) {
            auto [toVisit, parent]  = q.front();
            q.pop();

            for (const auto& nei: adjs[toVisit]) {
                if (parent == nei)
                    continue;
                if (visited.contains(nei))
                    return false;

                q.push({nei, toVisit});
            }

            visited.insert(toVisit);
        }

        return visited.size() == n;
    }
};
