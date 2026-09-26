class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for (const auto& p : knowledge) {
            map[p[0]] = p[1];
            
        }
        string key, r;
        bool in = false;
        for (char c : s) {
            if (c == '(') {
                in = true;
            } else if (c == ')') {
                const auto t = map.find(key);
                r += t == map.end() ? "?" : t->second;
                key = "";
                in = false;
            } else if (in) {
                key.push_back(c);
            } else {
                r.push_back(c);
            }
        }
        return r;
    }
};