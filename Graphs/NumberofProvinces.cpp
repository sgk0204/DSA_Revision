#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& isConnected){
        visited[node] = true;
        int n = isConnected.size();
        for(int i = 0; i < n; i++){
            if(isConnected[node][i] == 1 && !visited[i]){
                dfs(i, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int pro = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, visited, isConnected);
                pro++;
            }
        }
        return pro;
    }
};
int main(){
    Solution s;
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout << s.findCircleNum(isConnected) << endl;
    return 0;
}

//Complexity Analysis:
//Time Complexity: O(n^2) where n is the number of cities. We need to traverse the entire isConnected matrix once.
//Space Complexity: O(n) for the visited array and the recursion stack in the worst case
