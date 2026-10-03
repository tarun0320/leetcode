class Solution {
public:
    int longestValidParentheses(string s) {
       
        int answer = 0, depth = 0, start = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++depth;
            }
            else if (--depth < 0) {
                start = i;
                depth = 0;
            }
            else if (depth == 0) {
                answer = max(answer, i - start);
                
            }
        }
        depth = 0;
        start = s.size();
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++depth;
            }
            else if (--depth < 0) {
                start = i;
                depth = 0;
            }
            else if (depth == 0) {
                answer = max(answer, start - i);
            }
        }
        return answer;
        
    }
};