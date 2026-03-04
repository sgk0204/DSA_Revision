#include <bits/stdc++.h>
using namespace std;
class Solution{
public :
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }
        return (s+s).find(goal) != string::npos;
    }
};

int main(){
    Solution s;
    string str1 = "abcde";
    string str2 = "cdeab";
    cout << s.rotateString(str1, str2) << endl;
    return 0;
}
//Complexity Analysis̥
//Time Complexity: O(n) where n is the length of the input strings. We are concatenating the string s with itself, which takes O(n) time, and then we are searching for the substring goal in the concatenated string, which also takes O(n) time. Therefore, the overall time complexity is O(n).
//Space Complexity: O(n) since we are creating a new string by concatenating s with itself, which takes O(n) space. The space used for the input strings is not considered in the space complexity analysis since it is given as input and does not depend on the size of the output.