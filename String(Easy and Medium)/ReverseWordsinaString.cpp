#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int i = s.size() - 1;
        while(i >= 0){
            while( i >=0 && s[i] == ' '){
                i--;
            }
            if(i < 0) break;
            int end = i;
            while(i >= 0 && s[i] != ' '){
                i--;
            }
            string word = s.substr(i+1, end - i);

            if(!result.empty()){
                result += " ";
            }
            result += word;
        }
        return result;
    }
};
int main(){
    Solution s;
    string str = "  hello world  ";
    cout << s.reverseWords(str) << endl;
    return 0;
}
//Complexity Analysis
//Time Complexity: O(n) where n is the length of the input string. We are
//iterating through the input string once, so the time complexity is O(n).
//Space Complexity: O(n) since we are using a string to store the result, and