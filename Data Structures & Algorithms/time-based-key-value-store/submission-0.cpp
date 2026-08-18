class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> kv;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        kv[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto it = kv.find(key);
        if (it == kv.end())
            return "";

        const auto& values = it->second;
        
        int l = 0;
        int r = values.size() - 1;
        string res = "";

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (values[mid].first <= timestamp) {
                res = values[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};
