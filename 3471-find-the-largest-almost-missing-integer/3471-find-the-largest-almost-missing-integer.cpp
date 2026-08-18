class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> subarray_count;
        
        for (int i = 0; i<= n-k; ++i){
            unordered_set<int> unique_in_subarray;
            for(int j= i ; j<i + k; ++j){
                unique_in_subarray.insert(nums[j]);
            }
            for (int val : unique_in_subarray){
                subarray_count[val]++;
            }
        }
        int max_val = -1;
        for(auto& [ val, count]:subarray_count){
            if(count==1){
                max_val= max(max_val,val);
            }
        }
        return max_val;
        
    }
};