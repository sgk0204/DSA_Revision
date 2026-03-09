#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(), wordList.end());
        if(!words.count(endWord)) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto [str, step] = q.front();
            q.pop();
            if(str == endWord) return step;
            for(int i = 0; i < str.size(); i++){
                string temp = str;
                for(char c = 'a'; c <= 'z'; c++){
                    temp[i] = c;
                    if(words.count(temp)){
                        words.erase(temp);
                        q.push({temp, step +1});
                    }
                }
            }
        }
        return 0;
    }
};
int main(){
    Solution s;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}

//complexity analysis:
//Time complexity: O(N*M*26) where N is the number of words in the wordList and M is the length of each word. We generate at most 26*M new words for each of the N words.
//Space complexity: O(N) for the queue and the unordered_set to store the words. In the worst case, we may have to store all words in the queue.