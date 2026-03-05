#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int ans = 0;
        stack<char> st;
        for(char c: s){
            if(c == '('){
                st.push('(');
                count++;
            }
            ans = max(ans, count);
            if(c == ')'){
                st.pop();
                count--;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    string str = "(1+(2*3)+((8)/4))+1";
    cout << s.maxDepth(str) << endl; // Output: 3
    return 0;
}
//Complexity Analysis
//Time Complexity: O(n) where n is the length of the input string. We are iterating through the input string once, so the time complexity is O(n).
//Space Complexity: O(n) in the worst case, when all characters in the input string are opening parentheses '('. In this case, we would push all of them onto the stack, resulting in a space complexity of O(n). However, in general, the space complexity can be considered O(d), where d is the maximum depth of nested parentheses.