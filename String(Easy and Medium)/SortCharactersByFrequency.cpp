#include <bits/stdc++.h>
using namespace std;
class Sloution{
public:
    string frequencySort(string s) {
        unordered_map<char, int>freq;
        for(char c: s){
            freq[c]++;
        }
        vector<pair<char, int>> V(freq.begin(), freq.end());
        sort(V.begin(), V.end(), [](auto &a, auto &b){
            return a.second>b.second;
        });
        
        string ans = "";
        for(int i = 0; i < V.size(); i++){
            ans.append(V[i].second, V[i].first);
        }
        return ans;
    }
};
int main(){
    Sloution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl; // Output: "eert" or "eetr"
    return 0;
}

//coplexity analysis:
// Time complexity: O(n log n) due to the sorting step, where n is the number of unique characters in the input string.
// Space complexity: O(n) due to the space used for the frequency map and the vector of pairs.