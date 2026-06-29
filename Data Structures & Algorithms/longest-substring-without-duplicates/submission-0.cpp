class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int left=0;
        int ans=0;
        for(int right = 0; right < s.length(); right++){
            char c = s[right];
            if(mpp.find(c) != mpp.end() && mpp[c] >= left)
                left = mpp[c] + 1;
            
            ans = max(ans, right - left + 1);
            mpp[c] = right;
        }
        return ans;
    }
};
