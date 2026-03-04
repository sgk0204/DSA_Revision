#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0};
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }
        return true;
    }
};
int main(){
    Solution s;
    string str1 = "egg";
    string str2 = "add";
    cout << s.isIsomorphic(str1, str2) << endl;
    return 0;
}

//Complexity Analysis
//Time Complexity: O(n) where n is the length of the input strings. We are iterating through the input strings once, so the time complexity is O(n).
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the mapping arrays. The size of the mapping arrays is fixed at 256, which is independent of the input size, so it is considered O(1) space complexity.