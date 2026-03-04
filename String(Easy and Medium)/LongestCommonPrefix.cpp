#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size() - 1];
        for(int i = 0 ; i < min(first.size(), last.size()); i++){
            if(first[i] != last[i]){
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<string> str = {"flower","flow","flight"};
    cout << s.longestCommonPrefix(str) << endl;
    return 0;
}
//Complexity Analysis
//Time Complexity: O(n log n) where n is the number of strings in the input vector. This is because we are sorting the input vector, which takes O(n log n) time. The rest of the operations take O(m) time, where m is the length of the longest common prefix, which is at most O(n) in the worst case.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the result and the temporary variables. The sorting operation may take O(n) space in the worst case, but it is not considered in the overall space complexity since it is not part of the algorithm's logic.