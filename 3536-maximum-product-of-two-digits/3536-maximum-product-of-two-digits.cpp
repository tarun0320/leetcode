class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.rbegin(),s.rend());
        int d1=s[0]-'0';
        int d2=s[1]-'0';
        return d1*d2;
        
    }
};