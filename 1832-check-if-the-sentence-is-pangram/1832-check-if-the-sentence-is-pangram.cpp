class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length()<26)return false;
        std::unordered_set<char>seen(sentence.begin(),sentence.end());
        return seen.size()==26;
        
    }
};