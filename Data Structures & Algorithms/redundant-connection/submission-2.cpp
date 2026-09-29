class Solution {
private:
    unordered_set<int> cycleNodes;
    int startNode = -1;
    bool recording = false;

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjs;
        unordered_set<int> visited;

        for (const auto& e: edges) {
            adjs[e[0]].push_back(e[1]);
            adjs[e[1]].push_back(e[0]);
        }

        dfs(adjs, visited, 1, -1);

        for (int i = edges.size() - 1; i >= 0; i--) {
            if (cycleNodes.contains(edges[i][0]) && cycleNodes.contains(edges[i][1]))
                return edges[i];
        }

        return {};
    }

    bool dfs(unordered_map<int, vector<int>>& adjs, unordered_set<int>& visited, int toVisit, int parent) {
        if (visited.contains(toVisit)) {
            cycleNodes.insert(toVisit);
            startNode = toVisit;
            recording = true;
            return true;
        }

        visited.insert(toVisit);

        for (const auto& nei: adjs[toVisit]) {
            if (nei == parent)
                continue;

            if (dfs(adjs, visited, nei, toVisit)) {
                if (recording)
                    cycleNodes.insert(toVisit);

                if (startNode == toVisit)
                    recording = false;

                return true;
            }
        }

        return false;
    }
};
