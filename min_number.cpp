/*
You are given a 0-indexed integer array nums of even length and there is also an empty array arr. Alice and Bob decided to play a game where in every round Alice and Bob will do one move. The rules of the game are as follows:

    Every round, first Alice will remove the minimum element from nums, and then Bob does the same.
    Now, first Bob will append the removed element in the array arr, and then Alice does the same.
    The game continues until nums becomes empty.

Return the resulting array arr.
*/

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> min_nums;
        int i = 0;
        int len = nums.size()/2;
        do{
                i++;
                stack<int> temp;
            
                // alice's turn
                auto min_it = min_element(nums.begin(), nums.end());
                temp.push(*min_it);
                nums.erase(min_it);
                // bob's turn
                min_it = min_element(nums.begin(), nums.end());
                temp.push(*min_it);
                nums.erase(min_it);
            
                // put both the min value in minimum vector
                min_nums.push_back(temp.top());
                temp.pop();
                min_nums.push_back(temp.top());
                temp.pop();
        } while(i<len);
        return min_nums;
    }
};