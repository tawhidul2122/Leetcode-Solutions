// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        //remember to convert to "double"!
        double slope = (double)(coordinates[1][1] - coordinates[0][1]) / 
                (coordinates[1][0] - coordinates[0][0]);
        // cout << slope << endl;
        for(int i = 2; i < coordinates.size(); i++){
            vector<int> a = coordinates[i], b = coordinates[i-1];
            // cout << (double)(a[1] - b[1]) / (a[0] - b[0]) << endl;
            if(slope != (double)(a[1] - b[1]) / (a[0] - b[0])){
                return false;
            }
        }
        cout << endl;
        
        return true;
    }
};
