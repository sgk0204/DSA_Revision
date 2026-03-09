#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char>> &grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};
int main(){
    Solution s;
    vector<vector<char>> grid = {{'1','1','0','0','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','1','0','0'},
                                 {'0','0','0','1','1'}};
    cout << s.numIslands(grid) << endl; // Output: 3
    return 0;
}
//Compexity Analysis:
//Time Complexity: O(N*M) where N and M are the number of rows and columns in the grid. In the worst case, we may have to visit every cell in the grid.
//Space Complexity: O(N*M) in the worst case when the grid is filled with land (1s), the recursion stack can go as deep as N*M.