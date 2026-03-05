#include <bits/stdc++.h>
using namespace std;
class Solution {
public :
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;
        for(int i = 0; i < n; i++){
            unordered_map<char, int>freq;
            for(int j = i; j < n; j++){
                freq[s[j]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for(auto it : freq){
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }
                sum += (maxi - mini);
            }
        }
        return sum;
    }
};
int main(){
    Solution s;
    string str = "aabcb";
    cout << s.beautySum(str) << endl; // Output: 5
    return 0;
}
//Complexity Analysis
//Time Complexity: O(n^3) where n is the length of the input string. We have two nested loops to generate all possible substrings, which takes O(n^2) time, and for each substring, we are calculating the frequency of characters and finding the maximum and minimum frequency, which takes O(n) time in the worst case.
//Space Complexity: O(n) in the worst case, when all characters in the input string are unique. In this case, we would store the frequency of each character in the unordered_map, resulting in a space complexity of O(n). However, in general, the space complexity can be considered O(k), where k is the number of unique characters in the substring being evaluated.