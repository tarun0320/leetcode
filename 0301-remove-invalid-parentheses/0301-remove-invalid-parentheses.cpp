class Solution {
public:
    bool better(set<string> &a, set<string> &b) {
        if (a.empty()) {
            return false;
        }
        if (b.empty()) {
            return true;
        }
        if (a.begin()->length() + 1 > b.begin()->length()) {
            b.clear();
            return true;
        }
        return a.begin()->length() + 1 == b.begin()->length();
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        vector<set<string> > have(n + 1);
        have[0].insert("");
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                for (int j = i + 1; j > 0; --j) {
                    if (better(have[j - 1], have[j])) {
                        for (set<string>::iterator t = have[j - 1].begin(); t != have[j - 1].end(); ++t) {
                            have[j].insert(*t + "(");
                        }
                    }
                }
            }
            else if (s[i] == ')') {
                for (int j = 0; j <= i; ++j) {
                    if (better(have[j + 1], have[j])) {
                        for (set<string>::iterator t = have[j + 1].begin(); t != have[j + 1].end(); ++t) {
                            have[j].insert(*t + ")");
                        }
                        
                    }
                }
               
            }
            else {
                for (int j = 0; j <= i + 1; ++j) {
                    set<string> temp;
                    for (set<string>::iterator t = have[j].begin(); t != have[j].end(); ++t) {
                        temp.insert(*t + s[i]);
                    }
                    have[j] = temp;
                }
            }
        }
        vector<string> answer;
        for (set<string>::iterator t = have[0].begin(); t != have[0].end(); ++t) {
            answer.push_back(*t);
        }
        return answer;
    }
};