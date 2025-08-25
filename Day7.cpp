/* 2200. Find All K-Distant Indices in an Array:
You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i of nums for which there exists
at least one index j such that |i - j| <= k and nums[j] == key.

Return a list of all k-distant indices sorted in increasing order. */


class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            // Loop through every index j
            for(int j = 0; j < n; j++){
                // check the condition |i - j| <= k and nums[j] == key
                if(abs(i - j) <= k && nums[j] == key){
                    result.push_back(i);
                    break; // No need to check more j's for this i 
                }    
            }
        }

        return result;
    }
};
