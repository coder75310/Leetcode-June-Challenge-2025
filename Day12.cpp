/* 594. Longest Harmonious Subsequence:
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
 */


class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int maxLen = 0;
        for (auto& [num, freq] : count) {
            if (count.find(num + 1) != count.end()) {
                maxLen = max(maxLen, freq + count[num + 1]);
            }
        }
        return maxLen;
    }
};
