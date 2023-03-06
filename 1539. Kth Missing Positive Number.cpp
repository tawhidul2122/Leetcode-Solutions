class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //i: consider arr[1...i], index is 1-based
        int l = 0, r = arr.size();
        int m;
        
        while(l < r){
            m = (l+r+1) >> 1;
             if(m == 0 || arr[m-1] - m < k){
                l = m;
            }else{
                r = m-1;
            }
        }
        
        return l + k;
    }
};
