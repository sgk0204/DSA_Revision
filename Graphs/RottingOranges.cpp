#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int ans = 0;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!q.empty()){
            auto [p,t] = q.front();
            q.pop();
            ans = max(ans, t);
            for(int k = 0; k < 4; k++){
                int r = p.first + dr[k], c = p.second+dc[k];
                if(r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1 && !vis[r][c]){
                    vis[r][c] = 2;
                    q.push({{r,c}, t+1});
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << s.orangesRotting(grid) << endl;
    return 0;
}

//Complexity Analysis:
//Time Complexity: O(n*m) where n and m are the number of rows and columns in the grid. We need to traverse the entire grid once to find the initial rotten oranges and then again to check for any remaining fresh oranges.
//Space Complexity: O(n*m) for the visited array and the queue in the worst case when all oranges are rotten.