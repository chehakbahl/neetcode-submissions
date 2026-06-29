class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int ans=0;
        int max_freq=0;
        unordered_map<char,int>mpp;
        for(int right=0;right<s.size();right++){
            char c = s[right];
                mpp[c]++;
            max_freq=max(max_freq,mpp[c]);
            while((right-left+1)-max_freq > k){
                mpp[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
