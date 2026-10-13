class Solution {
public:

    int rows, cols;
    vector<vector<bool>> visited;

    bool exist(vector<vector<char>>& board, string word) {
        
        rows = board.size();
        cols = board[0].size();
        visited = vector<vector<bool>> (rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs (vector<vector<char>> & board, string word, int i, int j, int idx) {

        if (idx == word.length()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= rows || j >= cols || board[i][j] != word[idx] || visited[i][j]) {
            return false;
        }

        visited[i][j] = true;

        bool res = dfs (board, word, i + 1, j, idx + 1) ||
                   dfs (board, word, i - 1, j, idx + 1) ||
                   dfs (board, word, i, j + 1, idx + 1) ||
                   dfs (board, word, i, j - 1, idx + 1);

        visited[i][j] = false;

        return res;
    }
};
