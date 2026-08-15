class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0,res = nums.size();
        bool isAllZero= true;
        for(int n: nums){
            x^=n;
            if(n and isAllZero)
            isAllZero=false;
        }
        if(isAllZero)
        return 0;
        if(x)
        return res;
        return res-1;
    }
};