#include <iostream>
#include <vector>
using namespace std;

//OPTIMAL solution
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        int n = numbers.size();
        int *a = new int[n];
        for(int i = 0;i < n;i++)    a[i] = numbers[i];
        sort(numbers.begin(),numbers.end());
        int lhs = 0,rhs = n-1;
        while(rhs > lhs){
            if(numbers[lhs] + numbers[rhs] > target)    rhs--;
            else if(numbers[lhs] + numbers[rhs] < target)   lhs++;
            else{
                int id1,id2;
                for(int i = 0;i < n;i++){
                    if(a[i] == numbers[lhs]){
                        id1 = i + 1;
                        break;
                    }
                }
                for(int i = n - 1;i >= 0;i--){
                    if(a[i] == numbers[rhs]){
                        id2 = i + 1;
                        break;
                    }
                }
                res.push_back(min(id1,id2));
                res.push_back(max(id1,id2));
                return res;
            }
        }
    }
};

/*
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
*/

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums{3, 2, 4};
    // for (int i = 0; i < nums.size(); i++)
    //     cout << nums[i] << " ";
    vector<int> ans = twoSum(nums, 6);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

