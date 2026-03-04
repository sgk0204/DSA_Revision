#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    string largestOddNumber(string num) {
        int ind = -1;
        int i;
        for(i = num.length() - 1; i >= 0; i--){
            if((num[i] - '0') % 2 == 1){
                ind = i;
                break;
            }
        }
        i = 0;
        while(i <= ind && num[i] == '0') i++;
        return num.substr(i, ind - i + 1);
    }
};
int main(){
    Solution s;
    string str = "52";
    cout << s.largestOddNumber(str) << endl;
    return 0;
}
//Complexity Analysis
//Time Complexity: O(n) where n is the length of the input string. We are iterating through the input string once, so the time complexity is O(n).
//Space Complexity: O(n) since we are using a string to store the result, and in the worst case, the result can be of the same length as the input string.