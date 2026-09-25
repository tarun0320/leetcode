class Solution {
private:
    set<string> merge(const set<string> &s, const set<string> &t) {
        set<string> r;
        for (const auto &w1 : s) {
            for (const auto &w2 : t) {
                r.insert(w1 + w2);
            }
        }
        return r;
    }

public:
    set<string> dfs(const string &s, int &now) {
        set<string> all;
        for (set<string> one = {""};;) {
            if (now >= s.length() || s[now] == '}') {
                all.insert(one.begin(), one.end());
                ++now;
                break;
            }
            if (s[now] == '{') {
                one = merge(one, dfs(s, ++now));
            } else if (isalpha(s[now])) {
                one = merge(one, {s.substr(now++, 1)});
            } else {
                //one.erase("");
                all.insert(one.begin(), one.end());
                one = {""};
                ++now;
            }
        }
        return all;
    }

    vector<string> braceExpansionII(string expression) {
        vector<string> r;
        int now = 0;
        for (const auto& s : dfs(expression, now)) {
            r.push_back(s);
        }
        return r;     
    }
};