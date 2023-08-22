// https://leetcode.com/problems/toeplitz-matrix

class Solution {
    //diagonal is constant 
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int M1 = matrix.size();
        if(M1==0||M1==1) return true;
        int M2 = matrix[0].size();

        for(int i=0;i<M1-1;i++)
        {
            for(int j=0;j<M2-1;j++)
            {
                if(matrix[i][j] != matrix[i+1][j+1])
                    return false;
            }
        }

        return true;
    }
};