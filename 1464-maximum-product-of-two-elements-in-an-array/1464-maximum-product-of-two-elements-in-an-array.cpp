class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1 = 0, m2=0;
        for (int num:nums){
            if(num > m1){
                m2=m1;
                m1=num;
            } else if (num > m2){
                m2=num;
            }
        }
            return (m1-1) * (m2-1);


    }
};