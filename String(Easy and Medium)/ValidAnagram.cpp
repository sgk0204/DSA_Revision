#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(),t.end());
        if(s == t){
            return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout << sol.isAnagram(s,t) << endl; // Output: 1 (true)
    return 0;
}

//coplexity analysis:
// Time complexity: O(n log n) due to the sorting step, where n is the length of the input strings.
// Space complexity: O(1) if we ignore the space used by the sorting algorithm, otherwise O(n) due to the space used for sorting.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        vector<int> freq(26,0);
        for(int i = 0; i < s.length(); i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

//coplexity analysis:
// Time complexity: O(n) where n is the length of the input strings, since we traverse both strings once to count the frequency of characters.
// Space complexity: O(1) s̥ince the frequency array has a fixed size of 26, regardless of the input size.