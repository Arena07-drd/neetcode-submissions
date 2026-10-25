class Solution {
public:

    int ROWS, COLS;

    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            if (board[r][0] == 'O') {
                dfs(board, r, 0);
            }

            if (board[r][COLS-1] == 'O') {
                dfs(board, r, COLS-1);
            }
        }

        for (int c = 0; c < COLS; c++) {
            if (board[0][c] == 'O') {
                dfs(board, 0, c);
            }

            if (board[ROWS-1][c] == 'O') {
                dfs(board, ROWS-1, c);
            }
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }

    }

    void dfs(vector<vector<char>>& board, int i, int j) {

        if(i < 0 || i >= ROWS || j < 0 || j >= COLS || board[i][j] != 'O') {
            return;
        }

        board[i][j] = '#';
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);

    }
};
