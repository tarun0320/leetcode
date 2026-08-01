class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        return accumulate(sentences.begin(),sentences.end(),0,[](int maxCount,const string & s){
            return max(maxCount,(int)count(s.begin(),s.end(),' ')+1);
        });
        
    }
};