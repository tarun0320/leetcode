class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> v(3);
        for (int x : stones){
            ++v[x %3];
        }
        return v[0]&1? (abs(v[1]-v[2])>=3):(min(v[1],v[2])>0);

    }
};