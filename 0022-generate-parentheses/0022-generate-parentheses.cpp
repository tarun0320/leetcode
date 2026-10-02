class Solution {
public:
    void help(string s,int dep, int n,vector<string> &result) {
        if (dep < 0) {
            return;
        }
        if (dep > n - s.size()) {
            return;
        }
        if (s.size() == n) {
            result.push_back(s);
            return;
        }
        help(s + "(", dep + 1, n, result);
        help(s + ")", dep - 1, n, result);
        
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        help("", 0, n << 1, result);
        return result;
        
        
    }
};