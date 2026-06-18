class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int longest = 0;
        unordered_set<int> mpp(nums.begin(), nums.end());
        for (int num : mpp) {
            if (mpp.find(num - 1) == mpp.end()) {
                int temp = num;
                int len = 1;
                while (mpp.find(temp + 1) != mpp.end()) {
                    temp++;
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};
