class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //optimal solution using hashmap
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()){
                return true;
            }
            mpp[nums[i]]=i;
        }
        return false;
    }
};