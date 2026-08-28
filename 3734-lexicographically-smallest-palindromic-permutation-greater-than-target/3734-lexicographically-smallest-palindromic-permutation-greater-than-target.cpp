class Solution {

void make(string& s, int n) {
    string temp = s;
    if (n & 1) {
        temp.pop_back();
    }
    reverse(temp.begin(), temp.end());
    s += temp;
}

void make(string &r, const int n, vector<int>& have) {
    for (int i = 0; r.length() < n;) {
        if (have[i]) {
            r.push_back(i + 'a');
            --have[i];
        } else {
            ++i;
        }
    }
}

public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> have(26);
        for (char c : s) {
            ++have[c - 'a'];
        }
        char extra = '?';
        for (int i = 0; i < 26; ++i) {
            if (have[i] & 1) {
                if (extra != '?') return "";
                extra = 'a' + i;
            }
            have[i] >>= 1;
        }
        const int n = s.length(), m = n >> 1;
        string temp = target.substr(0, m);
        int mask = 0;
        for (char c : temp) {
            const int x = c - 'a';
            if (have[x]-- == 0) {
                mask |= 1 << x;
            }
        }
        for (;;) {
            if (mask == 0) {
                if (temp.length() == m) {
                    string r = temp;
                    if (extra != '?') {
                        r.push_back(extra);
                    }
                    make(r, n);
                    if (r > target) return r;        
                } else {
                    for (int i = target[temp.length()] - 'a' + 1; i < 26; ++i) {
                        if (have[i]) {
                            --have[i];
                            string r = temp;
                            r.push_back('a' + i);
                            make(r, m, have);
                            if (extra != '?') {
                                r.push_back(extra);
                            }
                            make(r, n);
                            return r;
                        }
                    }
                }
            }
            if (temp.empty()) {
                return "";
            }
            const int x = temp.back() - 'a';
            if (++have[x] == 0) {
                mask ^= 1 << x;
            }
            temp.pop_back();
        }
        return "";
    }
};