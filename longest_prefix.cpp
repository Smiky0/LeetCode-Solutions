#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "";
        char a;
        int j, i;
        for (i = 0; i < strs[0].size(); i++)
        {
            a = strs[0][i];
            // check if character matches
            for (j = 0; j < strs.size(); j++)
            {
                if (a != strs[j][i])
                {
                    return prefix;
                }
            }
            prefix += a;
        }
        cout << endl;
        return prefix;
    }
};