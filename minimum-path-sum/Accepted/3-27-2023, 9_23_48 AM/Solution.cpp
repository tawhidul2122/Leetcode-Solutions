// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        s_ = vector<vector<int>>(m, vector<int>(n, 0));
        
        return minPathSum(grid, n - 1, m - 1, n, m);
    }    
private:
    long minPathSum(const vector<vector<int>>& grid, 
                   int x, int y, int n, int m) {        
        if (x == 0 && y == 0) return grid[y][x];
        if (x < 0 || y < 0) return INT_MAX;
        if (s_[y][x] > 0) return s_[y][x];
        
        int ans = grid[y][x] + min(minPathSum(grid, x - 1, y, n, m),
                                   minPathSum(grid, x, y - 1, n, m));
        return s_[y][x] = ans;
    }
    
    vector<vector<int>> s_;
};