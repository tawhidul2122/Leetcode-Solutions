// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int shiftedBinarySearch(vector<int>&nums, int target, int left, int right) {
        if (left > right) return -1;
        int mid = (left + right) / 2;
        int numleft = nums[left];
        int numright = nums[right];
        int midNum = nums[mid];
        if (midNum == target) {
            return mid;
        }
        if (numleft <= midNum) { // left is sorted
            if (target >= numleft && target < midNum) {
                return shiftedBinarySearch(nums, target, left, mid - 1);
            } else {
                return shiftedBinarySearch(nums, target, mid + 1, right);
            }
        } else {
            if (target > midNum && target <= numright) {
                return shiftedBinarySearch(nums, target, mid + 1, right);
            } else {
                return shiftedBinarySearch(nums, target, left, mid - 1);
            }
        }
    }
   
    int search(vector<int>& nums, int target) {
        return shiftedBinarySearch(nums, target, 0, nums.size() - 1);
    }
};

