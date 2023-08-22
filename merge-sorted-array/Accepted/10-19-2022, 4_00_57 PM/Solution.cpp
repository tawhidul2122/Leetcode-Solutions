// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<m;i++){
            nums1[i]=nums1[i];
            }
        int j=m;
        for(int k=0;k<n;k++){
            nums1[j]=nums2[k];
            j++;
        }
        sort(nums1.begin(),nums1.end());
        }
        
        
    
};