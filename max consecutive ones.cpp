class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i, current=0, max=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0) current=0;
            else if(nums[i]==1){
                current++;
            }
            if(current>max) max=current;
        }
        return max;
    }
};
