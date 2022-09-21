class Solution {
    public int[] runningSum(int[] nums) {
        for(int i=1;i<nums.length;i++){
            nums[i]=nums[i-1]+nums[i]; //for 1= 1+0, 2=2+1, 3=3+2
        }
        
        return nums;
}
}