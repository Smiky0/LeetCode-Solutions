#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int j,k,sum;
    vector<vector<int>> triplets;
    vector<int> temp;
    // sort the array to avoid duplicate triplates
    sort(nums.begin(), nums.end());
    for (int i = 0; i<nums.size(); i++){
        j = i+1;
        k = nums.size()-1;

        while(nums[i]!=nums[j] && nums[i]!=nums[k] && nums[j]!=nums[k] && j<k){
            sum = nums[i]+nums[j]+nums[k];
            if(sum == 0){
                temp = {nums[i], nums[j], nums[k]};
                triplets.push_back(temp);
            }
            else if(sum>0){
                k--;
            }
            else{
                j++;
            }

        }
    }
    return triplets;
}

int main()
{
    
    return 0;
}