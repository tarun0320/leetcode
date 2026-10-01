class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                t.push(s[i]);
            } else if (t.empty()) {
                return false;
            } else if ((s[i] == ')' && t.top() == '(') || (s[i] == '}' && t.top() == '{') || (s[i] = ']' && t.top() == '[')) {
                    t.pop();
            } else {
                    return false;
            }
        }
        
        return t.empty();
    }
};