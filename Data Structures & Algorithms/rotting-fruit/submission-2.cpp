class Solution {
private:
    bool allRotten(const unordered_map<int, int> fruits) {
        for (const auto& [_, condition]: fruits)
            if (condition != 2)
                return false;
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> adjs;
        unordered_map<int, int> fruits;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 0)
                    fruits[cols * i + j] = grid[i][j];
            }
        }

        for (const auto& [pos, _]: fruits) {
            int col = pos % cols;
            if (fruits.contains(pos - cols)) {
                adjs[pos].push_back(pos - cols);
            }
            if (fruits.contains(pos + cols)) {
                adjs[pos].push_back(pos + cols);
            }
            if (col < cols - 1 && fruits.contains(pos + 1)) {
                adjs[pos].push_back(pos + 1);
            }
            if (col > 0 && fruits.contains(pos - 1)) {
                adjs[pos].push_back(pos - 1);
            }
        }

        queue<int> q;
        for (const auto& [pos, condition]: fruits)
            if (condition == 2)
                q.push(pos);
        
        int res = 0;
        while (true) {
            vector<int> fruitsToAdd;
            while (!q.empty()) {
                int f = q.front();
                q.pop();

                for (const auto nei: adjs[f]) {
                    if (fruits[nei] != 2) {
                        fruitsToAdd.push_back(nei);
                        fruits[nei] = 2;
                    }
                }
            }
            res++;
            if (fruitsToAdd.empty())
                break;
            for (const auto f: fruitsToAdd)
                q.push(f);
        }

        return allRotten(fruits) ? res - 1 : -1;
    }
};
