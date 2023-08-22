// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs

class Solution {
public:
    bool good(vector<int>& nums, int max_diff, int p){
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; ++i){
            if (nums[i + 1] - nums[i] <= max_diff){
                cnt++;
                if (cnt >= p)return true;
                i++;
            }
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0)return 0;
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.back() - nums[0];
        while (lo < hi){
            int mid = (lo + hi) / 2;
            if (good(nums, mid, p)){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};