class Solution {
public:

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},
                                         {0, 1}, {0, -1}};


    int ROWS, COLS;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        ROWS = heights.size();
        COLS = heights[0].size();

        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));

        for (int c = 0; c < COLS; ++c) {
            dfs(0, c, pacific, heights);
            dfs(ROWS-1, c, atlantic, heights);
        }

        for (int r = 0; r < ROWS; ++r) {
            dfs(r, 0, pacific, heights);
            dfs(r, COLS-1, atlantic, heights);
        }


        vector<vector<int>> res;

        for(int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;

    }

    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[r][c] = true;

        for (auto [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;

            if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, ocean, heights);
            } 
        }
    }
};
