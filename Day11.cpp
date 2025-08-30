/* 1498. Number of Subsequences That Satisfy the Given Sum Condition:
You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large,
return it modulo 10^9 + 7. */

 
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // Precompute powers of 2
        vector<int> pow2(n, 1);
        for (int i = 1; i < n; ++i) {
            pow2[i] = (pow2[i-1] * 2) % mod;
        }
        
        int left = 0, right = n - 1;
        int result = 0;
        
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + pow2[right - left]) % mod;
                ++left;
            } else {
                --right;
            }
        }
        
        return result;
    }
};

