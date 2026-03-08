#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(auto& pre: prerequisites){
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(int nei : adj[node]){
                inDegree[nei]--;
                if(inDegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        return count == numCourses;
    }
};
int main(){
    Solution s;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    cout << s.canFinish(numCourses, prerequisites) << endl; // Output: 1 (true)
    return 0;
}
//Complexity Analysis:
//Time Complexity: O(V + E) where V is the number of courses and E is the number of prerequisites. We need to traverse all courses and their prerequisites.
//Space Complexity: O(V + E) for the adjacency list and in-degree array. In the worst case, we may have all courses as prerequisites for each other, leading to O(V^2) space.   
