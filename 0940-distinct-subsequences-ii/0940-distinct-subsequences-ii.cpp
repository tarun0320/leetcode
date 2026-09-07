class Solution {
    const int M = 1000000007;
    
    void add(int &x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
    }
    
    void dec(int &x, int y) {
        if ((x -= y) < 0) {
            x += M;
        }
    }
    
public:
    int distinctSubseqII(string S) {
        vector<int> last(26);
        int r = 1;
        for (int i = 0; i < S.length(); ++i) {
            const int c = S[i] - 'a';
            const int p = r;
            add(r, r);
            dec(r, last[c]);
            last[c] = p;
        }
        dec(r, 1);
        return r;
        
    }
};  
