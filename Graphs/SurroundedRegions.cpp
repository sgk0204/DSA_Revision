#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int M, N;

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis) {
        // Base case: out of bounds, already visited, or 'X'
        if (i < 0 || i >= M || j < 0 || j >= N || vis[i][j] || board[i][j] == 'X') {
            return;
        }
        
        vis[i][j] = true;

        // DFS on neighbors
        dfs(i + 1, j, board, vis);
        dfs(i - 1, j, board, vis);
        dfs(i, j + 1, board, vis);
        dfs(i, j - 1, board, vis);
    }

public:
    void solve(vector<vector<char>>& board) {
        M = board.size();
        N = board[0].size();
        vector<vector<bool>> vis(M, vector<bool>(N, false));

        // 1 & 2. DFS from boundary 'O's to mark unflippable regions
        // Left and Right borders
        for (int i = 0; i < M; ++i) {
            if (board[i][0] == 'O' && !vis[i][0]) dfs(i, 0, board, vis);
            if (board[i][N - 1] == 'O' && !vis[i][N - 1]) dfs(i, N - 1, board, vis);
        }
        // Top and Bottom borders
        for (int j = 0; j < N; ++j) {
            if (board[0][j] == 'O' && !vis[0][j]) dfs(0, j, board, vis);
            if (board[M - 1][j] == 'O' && !vis[M - 1][j]) dfs(M - 1, j, board, vis);
        }

        // 3. Flip surrounded 'O's
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                // If 'O' is not visited, it means it's surrounded
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    sol.solve(board);
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}
//Complexity Analysis:
//Time Complexity: O(M*N) where M and N are the number of rows and columns in the board respectively. Each cell is visited at most once during the DFS.
//Space Complexity: O(M*N) in the worst case when all cells are 'O' and we need to store all of them in the recursion stack.