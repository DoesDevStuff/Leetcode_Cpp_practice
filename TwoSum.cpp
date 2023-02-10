#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j && nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}
};

/* Solution 2

class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            map<int, int> myMap;
            vector<int> index;
            for(int i=0; i<nums.size(); i++)
            {
                if(myMap.find(target - nums[i]) == myMap.end())
                {
                    myMap.insert({nums[i], i});
                } else if(myMap.find(target - nums[i]) != myMap.end())
                {
                    index.push_back(i);
                    index.push_back(myMap[target - nums[i]]);
                    return index;
                }
            }
            index.push_back(-1);
            index.push_back(-1);
            return index;
        }
};
*/
