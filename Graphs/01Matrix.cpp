#include <bits/stdc++.h>
using namespace std;
class Solution {
public: 
    vector<int> DIR = {0, 1, 0, -1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n; ++c){
                if(mat[r][c] == 0) q.emplace(r,c);
                else mat[r][c] = -1;
            }
        }
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i){
                int nr = r + DIR[i], nc = c + DIR[i+1];
                if(nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -1){
                    continue;
                }
                mat[nr][nc] = mat[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
        return mat;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    auto ans = sol.updateMatrix(mat);
    for(auto& row: ans){
        for(auto& x: row){
            cout << x << " ";
        }
        cout << endl;
    }
}
//Complexity Analysis:
//Time Complexity: O(m*n) where m and n are the number of rows and columns in the matrix respectively. Each cell is processed at most once.
//Space Complexity: O(m*n) in the worst case when all cells are 1s and we need to store all of them in the queue.