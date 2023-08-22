// https://leetcode.com/problems/stone-game-ii

class Solution {
public:
    vector<int> sum;
    vector<vector<int>> hash;
    int N;
    
    int helper(vector<int>& piles, int start, int M){
        if(start == N) return 0;
        
        if(N-start <= 2*M) return sum[start];
        
        if(hash[start][M] != 0) return hash[start][M];
        
        int opponent = INT_MAX; 
        for(int i = 1; i <= 2*M; i++){
            opponent = min(opponent, helper(piles, start+i, max(M, i)));
        }
        hash[start][M] = sum[start] - opponent;
        return hash[start][M];
    }
    
    int stoneGameII(vector<int>& piles) {
        N = piles.size();
        if(N == 0) return 0;
        
        sum = piles;
        for(int i = N-2; i >= 0; i--){
            sum[i] = sum[i+1] + piles[i];
        }
        
        hash = vector<vector<int>>(N, vector<int>(N, 0));
        return helper(piles, 0, 1);
    }
};