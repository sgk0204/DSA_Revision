#include <bits/stdc++.h>
using namespace std;
class Solution {
    string b;
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
public:
    void dfs(string word , vector<string> &seq){
        if(word == b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps = mpp[word];
        int sz = word.size();
        for(int i=0 ; i<sz ; i++){
            char org = word[i];
            for(char ch = 'a' ; ch <= 'z' ; ch++){
                word[i] = ch;
                if(mpp.find(word) != mpp.end()  && mpp[word] + 1 == steps){

                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }

    vector<vector<string>> findLadders(string st, string tar, vector<string>& word) {
        unordered_set<string> s(word.begin(),word.end());
        queue<string> q;
        q.push(st); 
        mpp[st] = 1;
        b = st;

        while(!q.empty()){
            string str = q.front();
            int steps = mpp[str];
            q.pop();
            if(str == tar) break;

            int wordLen = str.size(); 
            for(int i=0 ; i<wordLen ; i++){
                char org = str[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    str[i] = ch;
                    if(s.count(str) && mpp.find(str) == mpp.end()){
                        q.push(str);
                        mpp[str] = steps+1;
                    }
                }
                str[i] = org;
            }
        }
        if(mpp.find(tar) != mpp.end()){
            vector<string> seq;
            seq.push_back(tar);
            dfs(tar,seq);
        }
        
        return ans;
    }
};
int main(){
    Solution s;
    string st = "hit";
    string tar = "cog";
    vector<string> word = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> ans = s.findLadders(st,tar,word);
    for(auto it : ans){
        for(auto i : it) cout << i << " ";
        cout << endl;
    }
}
// complexity analysis
// time complexity: O(N * M^2) where N is the number of words in the word list and M is the length of each word. This is because we are generating all possible transformations for each word and checking if they exist in the map.
// space complexity: O(N * M) where N is the number of words in the word list and M is the length of each word. This is because we are storing all the words in the map and also storing the sequences in the answer vector.