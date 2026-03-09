#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto& pre: prerequisites){
            int course = pre[0];
            int pres = pre[1];
            adj[pres].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> order;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(int next : adj[node]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        if((int)order.size() == numCourses){
            return order;
        }
        return {};
    }
};
int main(){
    Solution s;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> order = s.findOrder(numCourses, prerequisites);
    for(int course : order){
        cout << course << " ";
    }
    cout << endl; // Output: 0 1 2 3
    return 0;
}
//Complexity Analysis:
//Time Complexity: O(V + E) where V is the number of courses and E is the number of prerequisites. We visit each course and prerequisite at most once.
//Space Complexity: O(V + E) for the adjacency list and the indegree array. In the worst case, the graph can be a complete graph where each course is a prerequisite for every other course, leading to O(V^2) space complexity.
