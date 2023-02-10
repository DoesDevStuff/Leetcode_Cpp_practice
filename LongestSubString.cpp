class Solution {//Time complexity: O(n)
public: //Space complexity: O(n)
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_set<char> substr;//Unordered set to store the characters of sliding window
        int i = 0, j = 0, max_i = 0;
        while(j < n){
            if(substr.find(s[j]) == substr.end())
            { //if new character of sliding window is not a repetition
                substr.insert(s[j]);
                max_i = max(max_i, ((j - i) + 1));
                j++;//moves right end of sliding window to remove repetition
            }
            else
            {
                substr.erase(s[i]);
                i++;//moves left end of sliding window to remove repetition
            }
        }
        return max_i;
    }
};
