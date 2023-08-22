// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        if(n == 0) return {-1, -1};
        
        int left = 0, right = n-1;
        
        while(left <= right){
            int mid = (left+right) >> 1;
            
            if(nums[mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        
        if(left >= n || nums[left] != target){
            return {-1, -1};
        }
        
        vector<int> ans = {left};
        
        left = 0;
        right = n-1;
        while(left <= right){
            int mid = (left+right) >> 1;

            if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        
        ans.push_back(right);
        
        return ans;
    }
};