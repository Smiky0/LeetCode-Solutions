#include <vector>
#include <stdio.h>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        // find max candy one kid has
        int max = candies[0];
        for (int i = 1; i < candies.size(); i++)
        {
            if (candies[i] > max)
            {
                max = candies[i];
            }
        }
        // mark true and false for max candy
        vector<bool> maxCandy;
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= max)
            {
                maxCandy.push_back(true);
            }
            else
            {
                maxCandy.push_back(false);
            }
        }
        return maxCandy;
    }
};