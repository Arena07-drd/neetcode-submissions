class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;

        vector<vector<int>> dirs = {{-1, 0}, {1, 0},
                                    {0, -1}, {0, 1}};
        
        while(!q.empty()) {
            int size = q.size();
            bool rotten = false;

                for (int k = 0; k < size; k++) {
                    auto [row, col] = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int r = row + dirs[i][0];
                        int c = col + dirs[i][1];
                        
                        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0 || grid[r][c] == 2) {
                            continue;
                        }

                        q.push({r, c});
                        grid[r][c] = 2;
                        fresh--;
                        rotten = true;
                    
                    }

                    
                }

                if(rotten) {time++;}

        }

        return fresh == 0 ? time : -1;
    }
};
