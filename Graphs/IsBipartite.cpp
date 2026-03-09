#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ifBipartite(int curr, vector<int> &color,vector<vector<int>>& graph, int currColor){
        color[curr] = currColor;

        for(auto neigh: graph[curr]){
            if(color[neigh] == -1){
                if(!(ifBipartite(neigh, color, graph, 1-currColor))) return false;
            }
            else if(color[neigh] == color[curr]) return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1)
                if(!(ifBipartite(i, color, graph, 0))) return false;
        }
  
        return true;
    }
};
int main(){
    Solution s;
    vector<vector<int>> graph = {{1,3}, {0,2}, {1,3}, {0,2}};
    cout << s.isBipartite(graph) << endl; // Output: true
    return 0;
}
//Complexity Analysis:
//Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph. We visit each vertex and edge at most once.
//Space Complexity: O(V) for the color array and the recursion stack in the worst case when the graph is a tree.