#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        long res = 0, total = 0;
        while(right < nums.size()){
            total += nums[right];
            while(nums[right] * static_cast<long>(right - left + 1) > total + k){
                total -= nums[left];
                left += 1;
            }
            res = max(res, static_cast<long>(right - left + 1));
            right += 1;
        }
        return static_cast<int>(res);
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,2,4};
    int k = 5;
    cout << s.maxFrequency(nums, k) << endl;
    return 0;
}

//Complexity Analysis
//Time Complexity: O(nlogn) where n is the number of elements in the input
//Space Complexity: O(1) since we are using only a constant amount of space to store the variables.