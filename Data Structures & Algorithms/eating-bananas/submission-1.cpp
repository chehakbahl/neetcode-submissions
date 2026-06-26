class Solution {
   private:
    bool canEatAll(vector<int>& piles, int K, int h) {
        long long hourspent = 0;
        for (int pile : piles) {
            hourspent += (pile + K - 1) / K;
        }
        return hourspent <= h;
    }

   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canEatAll (piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
