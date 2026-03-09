#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i <m; i++){
            dfs(grid, i, 0);
            dfs(grid, i, n-1);
        }
        for(int j = 0; j < n; j++){
            dfs(grid, 0, j);
            dfs(grid, m-1, j);
        }

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j <0 || j >= grid[0].size() || grid[i][j] != 1){
            return ;
        }
        grid[i][j] = -1;
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout << s.numEnclaves(grid) << endl;
    return 0;
}
//complexity analysis:
//Time complexity: O(m*n) where m and n are the number of rows and columns in the grid. We visit each cell at most once.
//Space complexity: O(m*n) in the worst case when all cells are land, the recursion stack can go as deep as m*n. In practice, it will be less due to the presence of water cells.