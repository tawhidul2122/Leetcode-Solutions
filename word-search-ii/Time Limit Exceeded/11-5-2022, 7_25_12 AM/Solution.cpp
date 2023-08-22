// https://leetcode.com/problems/word-search-ii

class Solution {
public:
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int wordLength = words.size();
        int m = board.size();
        int n = board[0].size();
        vector<string> res;
        for (int l = 0; l < wordLength; ++l) {
            bool find = false;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (board[i][j] == words[l][0] && DFS(board, i, j, m, n, 0, words[l])) {
                        res.push_back(words[l]);
                        find = true;
                        break;
                    }
                }
                if (find)
                    break;
            }
        }
        return res;
    }
    
    bool DFS(vector<vector<char>>& board, int r, int c, int rows, int cols, int ind, string& word) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[ind])
            return false;
        if (ind == word.length() - 1)
            return true;
        bool isExist = false;
        char orig = board[r][c];
        board[r][c] = '*';
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            isExist = isExist || DFS(board, nr, nc, rows, cols, ind + 1, word);
        }
        board[r][c] = orig;
        return isExist;
    }
};