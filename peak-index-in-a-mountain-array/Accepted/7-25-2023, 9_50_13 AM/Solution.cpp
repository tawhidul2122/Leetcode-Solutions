// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        //binary search
        int low = 0;
        int up = A.size()-1;
        int cur = A.size()/2;
        // cout << low << " " << up << " " << cur << endl;
        while(true){
        // cout << low << " " << up << " " << cur << endl;
            if(A[cur-1] < A[cur] && A[cur] < A[cur+1]){ //left side of mountain
                low = cur;
                cur = (cur+up)/2;
            }else if(A[cur-1] > A[cur] && A[cur] > A[cur+1]){ //right side
                up = cur;
                cur = (cur+low)/2;
            }else{
                return cur;
            }
        }
    }
};