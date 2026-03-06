#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int orgColor){
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != orgColor || image[i][j] == newColor) return; 

        image[i][j] = newColor;
        
        dfs(image, i-1, j, newColor, orgColor); // up
        dfs(image, i, j+1, newColor, orgColor); // right
        dfs(image, i+1, j, newColor, orgColor); // down
        dfs(image, i, j-1, newColor, orgColor); // left
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};
int main(){
    Solution s;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> ans = s.floodFill(image, sr, sc, color);
    for(auto i: ans){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

//Complexity Analysis:
//Time Complexity: O(n*m) where n and m are the number of rows and columns in the image. In the worst case, we may need to visit all pixels.
//Space Complexity: O(n*m) in the worst case when all pixels are of the same color and we need to change them all. This is due to the recursion stack.