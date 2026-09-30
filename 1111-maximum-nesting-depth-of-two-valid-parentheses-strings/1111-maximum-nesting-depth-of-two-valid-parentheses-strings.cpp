class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        const int n = seq.length();
        vector<int> r(n);
        for (int a = 0, b = 0, i = 0; i < seq.length(); ++i) {
            if (seq[i] == '(') {
                if (a < b) {
                    ++a;
                } else {
                    ++b;
                    r[i] = 1;
                }
            } else if (a > b) {
                --a;
            } else {
                --b;
                r[i] = 1;
            }
        }
        return r;
        
        
    }
};