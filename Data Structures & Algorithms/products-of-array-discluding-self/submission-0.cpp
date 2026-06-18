class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int p=1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(j!=i){
                    p=p*nums[j];
                }
            }
            ans.push_back(p);
            p=1;
        }
        return ans;
    }
};
