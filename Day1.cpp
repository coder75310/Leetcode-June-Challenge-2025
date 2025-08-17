/* 2966. Divide Array Into Arrays With Max Difference  :
You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.

Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:

The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them. */


class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // step 1: Sort the array
        vector<vector<int>> result;

        for(int i=0; i<nums.size(); i += 3){
            // Ensure we always pick 3 elements
            int a = nums[i], b = nums[i+1], c = nums[i+2];

            // step 2: check if max difference in group <=k
            if(c - a <= k){
                result.push_back({a,b,c});
            } else {
                return {}; // Invalid group found
            }
        }

        return result;
    }
};
