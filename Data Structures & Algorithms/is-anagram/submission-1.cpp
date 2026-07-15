class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        vector<int>s1(26,0);
        for(char c:s){
            s1[c-'a']++;
        }
        for(char c:t){
            s1[c-'a']--;
        }
        for(int i=0;i<26;i++){
            if(s1[i]!=0){
                return false;
            }
        }
        return true;
    }
};
