// https://leetcode.com/problems/tallest-billboard

class Solution {

private:
    const int OFFSET = 5000;

public:
    int tallestBillboard(vector<int>& rods) {

        vector<vector<int>> dp(20, vector<int>(10001, -1));
        int res = dfs(rods, 0, 0, dp);
        return res == INT_MIN ? 0 : res;
    }

private:
    int dfs(const vector<int>& rods, int index, int diff, vector<vector<int>>& dp){

        if(index == rods.size()) return diff == 0 ? 0 : INT_MIN;

        int state = diff + OFFSET;
        if(dp[index][state] != -1) return dp[index][state];

        int res =  dfs(rods, index + 1, diff, dp);

        int tres = dfs(rods, index + 1, diff - rods[index], dp);
        res = max(res, tres);

        tres = dfs(rods, index + 1, diff + rods[index], dp);
        res = max(res, tres + rods[index]);

        return dp[index][state] = res;
    }
};